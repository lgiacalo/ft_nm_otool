/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:06:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 15:36:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		ft_usage_otool(void)
{
	ft_putstr("\nUSAGE: ft_otool [options] <input files>\n\n");
	ft_putstr("OPTIONS:\n");
	ft_putstr("\t-h\t\t- Print the mach header\n");
	ft_putstr("\t-t\t\t- Print the section text\n");
	ft_putstr("\t-d\t\t- Print the section data\n");
	return (EXIT_FAILURE);
}

void	ft_error_void(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return ;
}

int		ft_error_int(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (EXIT_FAILURE);
}

void	*ft_error_star(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (NULL);
}
