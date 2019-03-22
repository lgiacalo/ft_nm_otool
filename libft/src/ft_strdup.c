/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:39:28 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/07/24 17:39:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	taille;
	char	*s2;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	taille = ft_strlen(s1);
	s2 = NULL;
	s2 = (char *)ft_memalloc(sizeof(char) * (taille + 1));
	while (s1[++i] != '\0')
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
