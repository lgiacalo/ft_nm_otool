/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:03:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 19:45:37 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (-2048);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int		ft_chrstr_ind(char c, char *str)
{
	int	i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (i);
		i++;
	}
	i++;
	return (-i);
}
