/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr_ind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 03:51:55 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/08/31 16:31:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_chrstr_ind(char c, char *str)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (i);
		i++;
	}
	i++;
	return (-i);
}
