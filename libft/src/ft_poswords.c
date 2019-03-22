/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poswords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 04:13:05 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:49:20 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	*ft_poswords(char const *s, char c)
{
	char	cc;
	int		*tab;
	int		i;
	int		emp;

	i = ft_nbwords(s, c);
	tab = ft_memalloc(sizeof(int) * (i + 1));
	i = 0;
	emp = 0;
	cc = (c == ' ') ? '\t' : c;
	while (s[i] != '\0')
	{
		while (s[i] == c || s[i] == cc)
			i++;
		if (s[i] == '\0')
			return (tab);
		tab[emp] = i;
		while (s[i] != '\0' && s[i] != c && s[i] != cc)
			i++;
		emp++;
	}
	return (tab);
}
