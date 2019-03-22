/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:57:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 06:30:37 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_power(int nb, int power)
{
	int resultat;

	resultat = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	resultat = ft_power(nb, power - 1) * nb;
	return (resultat);
}
