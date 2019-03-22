/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_pnumbers_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 03:13:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/04 03:13:59 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_len_pnumbers_base(unsigned long long int n, char *base)
{
	int				len;
	unsigned int	nbr_base;

	if (!(ft_verif_base(base)))
		return (0);
	nbr_base = (unsigned int)ft_strlen(base);
	len = 1;
	while (n >= nbr_base)
	{
		n = n / nbr_base;
		len++;
	}
	return (len);
}
