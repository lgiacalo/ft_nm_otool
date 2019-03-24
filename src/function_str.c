/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 19:44:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	*ft_strndup(char *s1, int len)
{
	char	*ret;

	if (!s1 || !len)
		return (NULL);
	ret = (char *)ft_memalloc(len + 1);
	return (ft_memcpy(ret, s1, len));
}

/*
**	Fonction strlen special nm avec ft_is_safe()
**		Mais comment savoir si str totalement en dehors du fichier ?
*/

int 	ft_strlen_nm(char *str)
{
	int	i;

	i = -1;
	while (str && ft_is_safe(str, ++i) && str[i] != '\0');
	return (i);
}

void	ft_print_int(char *str1, long long int nbr, char *str2)
{
	ft_fdprintf(FDD, "%s%lld%s", str1, nbr, str2);
}

void	ft_print_str(char *str1, char *str2, char *str3)
{
	ft_fdprintf(FDD, "%s%s%s", str1, str2, str3);
}
