/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:08:23 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	*ft_strndup(char *s1, int len)
{
	char	*ret;

	if (!s1 || !len)
		return (NULL);
	if (!(ret = (char *)ft_memalloc(len + 1)))
		return (NULL);
	return (ft_memcpy(ret, s1, len));
}

int		ft_strlen_nm(char *str)
{
	int	i;

	i = 0;
	while (str && ft_is_safe(str, i) && str[i] != '\0')
		i++;
	return (i);
}

void	ft_print_int(char *str1, long long int nbr, char *str2)
{
	ft_printf("%s%lld%s", str1, nbr, str2);
}

void	ft_print_str(char *str1, char *str2, char *str3)
{
	ft_printf("%s%s%s", str1, str2, str3);
}
