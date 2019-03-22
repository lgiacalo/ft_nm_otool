/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:00:01 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:44:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_len_numbers(int n)
{
	long int	nbr;
	int			len;

	nbr = n;
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
