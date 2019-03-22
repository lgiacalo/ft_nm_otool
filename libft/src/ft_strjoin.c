/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:40:30 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:51:54 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		k;

	k = 0;
	if (!(s1) || !(s2))
		return (NULL);
	ret = ft_memalloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1 && *s1)
	{
		ret[k++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		ret[k++] = *s2;
		s2++;
	}
	ret[k] = '\0';
	return (ret);
}
