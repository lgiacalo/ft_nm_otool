/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:44:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:46:34 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = -1;
	while (dst[i] != '\0' && i < size)
		i++;
	if (dst[i] != '\0')
		return (size + ft_strlen(src));
	while (src[++k] != '\0' && i < size - 1)
	{
		dst[i] = src[k];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src) - k);
}
