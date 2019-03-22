/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:44:19 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:25:35 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = -1;
	while (src[++i] != '\0' && i < len)
		dst[i] = src[i];
	i--;
	while (++i < len)
		dst[i] = '\0';
	return (dst);
}
