/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 03:57:41 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/18 02:41:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstrchr(char *s1, char *s2)
{
	int	ret;

	ret = 0;
	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		ret = ft_chrstr_ind(*s1, s2);
		if (ret == -1)
			return (NULL);
		if (ret >= 0)
			return (s1);
		s1++;
	}
	return (NULL);
}
