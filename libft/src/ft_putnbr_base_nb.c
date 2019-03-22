/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:07:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/04 04:39:25 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_putnbr_base_nb(long long int n, char *base)
{
	int						i;
	unsigned long long int	nbr;
	unsigned int			nbr_base;

	i = 0;
	if ((ft_verif_base(base)) == 0)
		return (-1);
	nbr_base = (unsigned int)ft_strlen(base);
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchar('-');
		i = 1;
	}
	else
		nbr = n;
	(nbr < nbr_base) ? ft_putchar(base[nbr]) : 0;
	(nbr < nbr_base) ? i++ : 0;
	if (nbr >= nbr_base)
	{
		i = i + ft_putnbr_base_nb((nbr / nbr_base), base);
		i = i + ft_putnbr_base_nb((nbr % nbr_base), base);
	}
	return (i);
}
