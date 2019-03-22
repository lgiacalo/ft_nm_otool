/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpnbr_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 03:20:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/04 04:39:26 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putpnbr_nb(unsigned long long int n)
{
	int						i;
	unsigned long long int	nbr;

	nbr = n;
	i = 0;
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
