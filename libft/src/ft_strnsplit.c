/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:48:56 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/07/23 22:29:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_strlen_nb_lettres(char const *s, char c, int i)
{
	char	cc;
	int		j;

	j = 0;
	cc = (c == ' ') ? '\t' : c;
	while (s[i] != '\0' && s[i] != c && s[i] != cc)
	{
		i++;
		j++;
	}
	return (j);
}

char		**ft_strnsplit(char const *s, char c, int start)
{
	int		nb_mots;
	int		i;
	int		k;
	int		*tab;
	char	**dest;

	if (!s || ((nb_mots = (ft_nbwords(s, c) - start)) < 1))
		return (NULL);
	dest = ft_memalloc(sizeof(char *) * (nb_mots + 1));
	dest[nb_mots] = 0;
	i = -1;
	tab = ft_poswords(s, c);
	while (++i < nb_mots)
	{
		k = -1;
		dest[i] = ft_memalloc(sizeof(char)\
				* (ft_strlen_nb_lettres(s, c, tab[i + start]) + 1));
		while (++k < ft_strlen_nb_lettres(s, c, tab[i + start]))
			dest[i][k] = s[tab[i + start] + k];
		dest[i][k] = '\0';
	}
	free(tab);
	return (dest);
}
