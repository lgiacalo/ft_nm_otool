/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:37:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 05:37:59 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrev(char *str)
{
	int taille;
	int i;
	int temp;
	int k;

	i = 0;
	taille = ft_strlen(str);
	k = taille;
	while (i < taille / 2)
	{
		temp = str[i];
		str[i] = str[k - i - 1];
		str[k - i - 1] = temp;
		i++;
	}
	return (str);
}
