/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 06:03:56 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/19 22:41:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/../include/libft.h"

static int	ft_sqrt2(int nb)
{
	int i;
	int racine;

	i = 0;
	racine = 0;
	if (nb > 2147395600)
		return (0);
	while (nb >= racine)
	{
		racine = i * i;
		if (nb == racine)
			return (i);
		i++;
	}
	return (i);
}

int			ft_is_prime(int nb)
{
	int i;
	int racine;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	racine = ft_sqrt2(nb);
	if (nb % 2 == 0)
		return (0);
	while (i <= racine)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
