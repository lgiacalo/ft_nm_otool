/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:03:20 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 21:19:55 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	ft_atoi(const char *str)
{
	int resultat;
	int signe;

	signe = 1;
	resultat = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
	{
		resultat = 10 * resultat + (*str - '0');
		str++;
	}
	return (resultat * signe);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && i < (n - 1) && s1[i] == s2[i])
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
