/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:42:23 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:52:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	taille;

	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	ret = ft_memalloc(sizeof(char) * (taille + 1));
	taille = -1;
	while (s[++taille] != '\0')
		ret[taille] = f(s[taille]);
	ret[taille] = '\0';
	return (ret);
}
