/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 06:00:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 06:01:11 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_sqrt(int nb)
{
	int i;
	int racine;

	i = 0;
	racine = 0;
	if (nb > 2147395600)
		return (0);
	if (nb < 0)
		return (0);
	while (nb >= racine)
	{
		racine = i * i;
		if (nb == racine)
			return (i);
		i++;
	}
	return (0);
}
