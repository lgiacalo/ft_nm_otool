/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:25:38 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/07/23 15:26:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < size)
	{
		*(unsigned char*)(tab + i) = '\0';
		i++;
	}
	return ((void*)tab);
}
