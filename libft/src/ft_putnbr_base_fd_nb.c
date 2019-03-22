/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd_nb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:12:03 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/21 11:02:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_putnbr_base_fd_nb(int n, char *base, int fd)
{
	int				i;
	long long int	nbr;
	int				nbr_base;

	nbr = n;
	i = 0;
	if ((ft_verif_base(base)) == 0)
		return (-1);
	nbr_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
		i = 1;
	}
	(nbr < nbr_base) ? ft_putchar_fd(base[nbr], fd) : 0;
	(nbr < nbr_base) ? i++ : 0;
	if (nbr >= nbr_base)
	{
		i = i + ft_putnbr_base_fd_nb((nbr / nbr_base), base, fd);
		i = i + ft_putnbr_base_fd_nb((nbr % nbr_base), base, fd);
	}
	return (i);
}
