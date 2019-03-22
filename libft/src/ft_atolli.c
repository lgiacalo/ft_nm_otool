/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:34:52 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/06 06:41:58 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/../include/libft.h"

long long int	ft_atolli(const char *str)
{
	long long int	resultat;
	int				signe;

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
