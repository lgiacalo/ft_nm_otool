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

int		ft_is_safe(void *ptr, size_t size)
{
	if (env()->ptr <= ptr
			&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	*ft_safe(void *ptr, size_t size)
{
	if (env()->ptr <= ptr
			&& (env()->ptr + env()->file_size) >= (ptr + size))
		return (ptr);
	return (NULL);
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
	if (s[0] == '#')
	{
		nb = ft_get_len_name_header_line(ptr);
		if (!ft_is_safe((void *)(s + 60), nb))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
