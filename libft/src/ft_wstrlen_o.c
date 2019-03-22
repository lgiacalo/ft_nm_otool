/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 06:31:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/15 07:15:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <wchar.h>

int	ft_wstrlen_o(wchar_t *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		i += ft_wcharlen_o(*str);
		str++;
	}
	return (i);
}
