/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 06:07:50 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/12/19 22:40:46 by lgiacalo         ###   ########.fr       */
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
		return (46340);
	while (nb >= racine)
	{
		racine = i * i;
		if (nb == racine)
			return (i);
		i++;
	}
	return (i - 1);
}

static int	ft_is_prime2(int nb)
{
	int i;
	int racine;

	i = 3;
	if (nb == 0 || nb == 1)
		return (0);
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

int			ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_is_prime2(nb) == 0)
		nb++;
	return (nb);
}
