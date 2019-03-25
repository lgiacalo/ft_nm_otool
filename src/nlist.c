/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/10 20:07:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

//TODO: A faire fonction pour list t_line
// attention si name == NULL pas de free !

char	*ft_record_name_symbol(char *name)
{
	int	len;
	char	*str;

	len = ft_strlen_nm(name);
	str = ft_strndup(name, len); //TODO: attention exit() dans memalloc()
	// si probleme malloc, remonter programme pour sortir !! et print ERROR !
	return (str);
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
		c = n_sect + '0';
	else if (tmp == N_UNDF)
	{
		if ((n_type & N_EXT) && n_value)
			return ('C');
		c = 'u';
	}
	if (n_type & N_EXT)
		c = ft_toupper(c);
	return (c);
}

void	ft_gestion_nlist(char *n_strx, uint8_t n_type, uint8_t n_sect, uint64_t n_value)
{
	t_line					line;

	//TODO: enregistrement des infos dans struct line + send fonction add + tri to list chainee
	line.name = ft_record_name_symbol(n_strx);
	line.addr = n_value;
	line.sym = ft_record_symbol(n_type, n_sect, n_value);

	ft_print_line(&line, 0);
	ft_fdprintf(FDD, "%016llx %c %s\n", line.addr, line.sym, line.name);
	ft_fdprintf(FDD, "\t n_type = %#x / n_sect = %d\n\n\n", n_type, n_sect);
}
