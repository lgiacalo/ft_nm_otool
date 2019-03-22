/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:51:12 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/15 06:35:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_putwstr_fd_nb(wchar_t *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		i += ft_putwchar_fd(*str, fd);
		str++;
	}
	return (i);
}
