/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:28:24 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 04:44:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (*(unsigned char*)(s1 + i) ==
			*(unsigned char*)(s2 + i) && (i + 1) < n)
		i++;
	return ((*(unsigned char*)(s1 + i)) - (*(unsigned char*)(s2 + i)));
}
