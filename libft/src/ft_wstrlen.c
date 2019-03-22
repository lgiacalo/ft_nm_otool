/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 07:11:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/15 07:15:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <wchar.h>

int	ft_wstrlen(wchar_t *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
