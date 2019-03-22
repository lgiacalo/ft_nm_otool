/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:23:00 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/16 18:57:24 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/../include/libft.h"

int	ft_atoi(const char *str)
{
	int resultat;
	int signe;

	signe = 1;
	resultat = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		resultat = 10 * resultat + (*str - '0');
		str++;
	}
	return (resultat * signe);
}
