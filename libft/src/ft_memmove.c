/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:29:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:39:01 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src <= dst)
	{
		while (i < len)
		{
			i++;
			*(unsigned char*)(dst + len - i) =
			*(unsigned char*)(src + len - i);
		}
	}
	else
	{
		while (i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	return (dst);
}
