/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:23:27 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	*ft_record_name_symbol(char *name)
{
	int		len;
	char	*str;

	len = ft_strlen_nm(name);
	str = ft_strndup(name, len);
	if (len > 0 && !str)
		return ((void *)-1);
	return (str);
}

char	ft_record_symbol_section(uint8_t n_sect)
{
	t_sym	sym;

	sym = env()->symbol;
	if (sym.t == n_sect)
		return ('t');
	if (sym.d == n_sect)
		return ('d');
	if (sym.b == n_sect)
		return ('b');
	return ('s');
}

char	ft_record_symbol(uint8_t n_type, uint8_t n_sect, uint64_t n_value)
{
	char	c;
	uint8_t	tmp;

	c = '?';
	tmp = n_type & N_TYPE;
	if (tmp == N_ABS)
		c = 'a';
	else if (tmp == N_INDR)
		c = 'i';
	else if (tmp == N_SECT)
		c = ft_record_symbol_section(n_sect);
	else if (tmp == N_UNDF)
	{
		if ((n_type & N_EXT) && n_value)
			c = 'C';
		c = 'u';
	}
	if (n_type & N_EXT)
		c = ft_toupper(c);
	return (c);
}

int		ft_nlist(char *n_strx, uint8_t n_type, uint8_t n_sect, uint64_t n_value)
{
	t_line					line;
	t_line					*new;

	line.name = ft_record_name_symbol(n_strx);
	if (line.name == (void *)-1)
		return (ft_error_int(ERR_MALLOC));
	line.addr = n_value;
	line.sym = ft_record_symbol(n_type, n_sect, n_value);
	if (!(new = ft_line_new(line)))
		return ((ft_error_int(ERR_MALLOC)));
	ft_line_add(new, ft_tri_ascii);
	//TODO: error numero symbol
	// ft_fdprintf(1, " -%s- Char = %c // N_sect = %d \n", line.name, line.sym, n_sect);
	return (EXIT_SUCCES);
}
