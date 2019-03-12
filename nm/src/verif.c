/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 20:57:19 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 12:19:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

size_t	ft_align(size_t nb, size_t modulo)
{
	if ((nb % modulo) == 0)
		return (nb);
	return (((nb / modulo) + 1) * modulo);
}

int		ft_is_safe(void *ptr, size_t size)
{
	if (ptr && env()->ptr <= ptr
			&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	*ft_safe(void *ptr, size_t size)
{
	if (ptr && env()->ptr <= ptr
			&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (ptr);
	return (NULL);
}

int		ft_verif_base(char *str, int base, int len)
{
	int	i;

	if (!str || base < 2 || len <= 0)
		return (EXIT_SUCCESS);
	i = 0;
	while (i < len)
	{
		if (((str[i] - '0') < 0 || (str[i] - '0') >= base) && str[i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
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
		return (EXIT_FAILURE);
	s = (char *)ptr;
	if (s[58] != 0x60 || s[59] != 0x0A)
		return (EXIT_FAILURE);
	if (s[0] == '#' && s[1] == '1' && s[2] == '/')
	{
		nb = ft_get_len_name_header_line(ptr);
		if (!ft_is_safe((void *)(s + 60), nb) || !ft_verif_base(s + 3, 10, 2))
			return (EXIT_FAILURE);
	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
