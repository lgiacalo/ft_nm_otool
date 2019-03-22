/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:09:04 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/21 10:55:56 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_fd_nb(int n, int fd)
{
	int			i;
	long int	nbr;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
		i = 1;
	}
	if (nbr < 10)
	{
		ft_putchar_fd((nbr + '0'), fd);
		i++;
	}
	if (nbr >= 10)
	{
		i = i + ft_putnbr_fd_nb(nbr / 10, fd);
		i = i + ft_putnbr_fd_nb(nbr % 10, fd);
	}
	return (i);
}
