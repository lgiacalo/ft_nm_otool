/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:04:29 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/21 10:55:11 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	long int	nbr;
	int			nbr_base;

	nbr = n;
	if ((ft_verif_base(base)) == 0)
		return ;
	nbr_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr < nbr_base)
		ft_putchar_fd(base[nbr], fd);
	if (nbr >= nbr_base)
	{
		ft_putnbr_base_fd((nbr / nbr_base), base, fd);
		ft_putnbr_base_fd((nbr % nbr_base), base, fd);
	}
}
