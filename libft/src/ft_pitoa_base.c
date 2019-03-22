/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 03:13:05 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:43:53 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_pitoa_base(unsigned long long int n, char *base)
{
	char	*ret;
	int		len;
	int		nbr_base;

	if ((len = ft_len_pnumbers_base(n, base)) == 0)
		return (NULL);
	ret = ft_memalloc(sizeof(char) * (len + 1));
	nbr_base = ft_strlen(base);
	ret[0] = '0';
	ret[len] = '\0';
	while (n > 0)
	{
		ret[len - 1] = base[n % nbr_base];
		n = n / nbr_base;
		len--;
	}
	return (ret);
}
