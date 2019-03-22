/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:42:14 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/07 06:44:23 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isnumber(char *nb)
{
	char	*ret;
	int		i;

	i = 0;
	if (!nb || nb[i] == '\0')
		return (0);
	ret = ft_strtrim(nb);
	if (ret && (ret[i] == '+' || ret[i] == '-') && ft_isdigit(ret[i + 1]))
		i++;
	while (ret && ret[i] != '\0')
	{
		if (!ft_isdigit(ret[i]))
		{
			free(ret);
			return (0);
		}
		i++;
	}
	if (!ret)
		return (0);
	free(ret);
	return (1);
}
