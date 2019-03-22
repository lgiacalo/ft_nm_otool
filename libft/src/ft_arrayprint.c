/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:48:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/09/03 17:50:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_arrayprint(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != '\0')
	{
		ft_putstr((const char*)tab[i]);
		ft_putchar('\n');
		i++;
	}
}
