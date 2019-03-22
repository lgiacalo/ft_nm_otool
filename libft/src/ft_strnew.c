/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:44:57 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:54:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	str = ft_memalloc(sizeof(char) * (size + 1));
	while (++i <= size)
		str[i] = '\0';
	return (str);
}
