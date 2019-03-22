/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_numbers_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:15:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:48:00 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_len_numbers_base(long long int n, char *base)
{
	unsigned long long int	nbr;
	int						len;
	unsigned int			nbr_base;

	if (!(ft_verif_base(base)))
		return (0);
	nbr_base = (unsigned int)ft_strlen(base);
	len = 1;
	if (n < 0)
	{
		if (nbr_base == 10)
			len++;
		nbr = n * -1;
	}
	else
		nbr = n;
	while (nbr >= nbr_base)
	{
		nbr = nbr / nbr_base;
		len++;
	}
	return (len);
}
