/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:46:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/26 15:21:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	i;
	size_t	len;

	ret = NULL;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (*(s + i) == (char)c)
			ret = (char *)(s + i);
		i++;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (ret);
}
