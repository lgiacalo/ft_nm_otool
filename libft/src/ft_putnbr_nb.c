/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:10:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/04 04:39:24 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putnbr_nb(long long int n)
{
	int						i;
	unsigned long long int	nbr;

	i = 0;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
		i = 1;
	}
	else
		nbr = n;
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		i++;
	}
	if (nbr >= 10)
	{
		i = i + ft_putnbr_nb(nbr / 10);
		i = i + ft_putnbr_nb(nbr % 10);
	}
	return (i);
}
