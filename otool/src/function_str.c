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

#include "ft_otool.h"

void	ft_print_int(char *str1, long long int nbr, char *str2)
{
	ft_putstr(str1);
	ft_putnbr(nbr);
	ft_putstr(str2);
}

void	ft_print_str(char *str1, char *str2, char *str3)
{
	ft_putstr(str1);
	ft_putstr(str2);
	ft_putstr(str3);
}

void	ft_putstr(const char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
