/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:12:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/03 21:10:24 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr_fd_nb(char const *s, int fd)
{
	size_t	i;

	if (!s)
		return (-1);
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}
