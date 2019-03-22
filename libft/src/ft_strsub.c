/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:46:58 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:58:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!s || (int)len < 0)
		return (NULL);
	ret = ft_memalloc(sizeof(char) * (len + 1));
	while (s[i] != '\0' && i < len)
	{
		ret[i] = s[(size_t)start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
