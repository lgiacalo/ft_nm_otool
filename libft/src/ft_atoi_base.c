/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:19:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:46:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi_base(const char *str, char *base)
{
	int resultat;
	int signe;
	int	ret;
	int	nbr_base;

	resultat = 0;
	if (!str || *str == '\0')
		return (0);
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (!(ft_verif_base(base)))
		return (0);
	nbr_base = ft_strlen(base);
	signe = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while ((ret = ft_chrstr_ind(*str, base)) >= 0)
	{
		resultat = nbr_base * resultat + ret;
		str++;
	}
	return (resultat * signe);
}
