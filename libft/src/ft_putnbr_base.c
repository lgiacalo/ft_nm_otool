/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:02:21 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/04 03:42:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_base(int n, char *base)
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
		ft_putchar('-');
	}
	if (nbr < nbr_base)
		ft_putchar(base[nbr]);
	if (nbr >= nbr_base)
	{
		ft_putnbr_base((nbr / nbr_base), base);
		ft_putnbr_base((nbr % nbr_base), base);
	}
}
