/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrchr_ind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 03:54:51 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/08/29 18:40:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strstrchr_ind(char *s1, char *s2)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0')
	{
		ret = ft_chrstr_ind(s1[i], s2);
		if (ret >= 0)
			return (i);
		i++;
	}
	i++;
	return (-i);
}
