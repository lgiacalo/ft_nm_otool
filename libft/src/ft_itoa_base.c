/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:17:19 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:47:58 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_itoa_base(long long int n, char *base)
{
	unsigned long long int	nbr;
	char					*ret;
	int						len;
	int						nbr_base;

	if ((len = ft_len_numbers_base(n, base)) == 0)
		return (NULL);
	ret = ft_memalloc(sizeof(char) * (len + 1));
	nbr_base = ft_strlen(base);
	ret[0] = '0';
	ret[len] = '\0';
	nbr = (n < 0) ? (n * -1) : n;
	if (n < 0)
		ret[0] = '-';
	while (nbr > 0)
	{
		ret[len - 1] = base[nbr % nbr_base];
		nbr = nbr / nbr_base;
		len--;
	}
	return (ret);
}
