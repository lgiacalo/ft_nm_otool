/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:48:03 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/03 17:51:18 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s)
{
	char		*ret;
	size_t		i;
	size_t		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n'\
				|| s[len - 1] == '\t'))
		len--;
	if (len == 0)
		return (NULL);
	else
		ret = ft_strsub(s, i, (len - i));
	return (ret);
}
