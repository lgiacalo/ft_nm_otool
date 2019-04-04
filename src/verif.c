/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:57:19 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:32:53 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_is_safe(void *ptr, size_t size)
{
	if (ptr && env()->ptr <= ptr
		&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}

void	*ft_safe(void *ptr, size_t size)
{
	if (ptr && env()->ptr <= ptr
		&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (ptr);
	return (NULL);
}

int		ft_verif_base_nm(char *str, int base, int len)
{
	int	i;

	if (!str || base < 2 || len <= 0)
		return (EXIT_SUCCES);
	i = 0;
	while (i < len)
	{
		if (((str[i] - '0') < 0 || (str[i] - '0') >= base) && str[i] != ' ')
			return (EXIT_FAILUR);
		i++;
	}
	return (EXIT_SUCCES);
}

int		ft_get_len_name_header_line(void *ptr)
{
	int	nb;

	nb = ft_atoi(((char *)ptr) + 3);
	return (nb);
}

int		ft_verif_header_line(void *ptr)
{
	char	*s;
	int		nb;

	if (!ft_is_safe(ptr, 60))
		return (EXIT_FAILUR);
	s = (char *)ptr;
	if (s[58] != 0x60 || s[59] != 0x0A)
		return (EXIT_FAILUR);
	if (s[0] == '#' && s[1] == '1' && s[2] == '/')
	{
		nb = ft_get_len_name_header_line(ptr);
		if (!ft_is_safe((void *)(s + 60), nb)
			|| !ft_verif_base_nm(s + 3, 10, 2))
			return (EXIT_FAILUR);
	}
	else
		return (EXIT_FAILUR);
	return (EXIT_SUCCES);
}
