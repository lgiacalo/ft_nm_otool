/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:06:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 15:53:28 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"


int		ft_usage_nm(void)
{
	ft_putstr("\nUSAGE: ft_nm [options] <input files>\n\n"); 
	ft_putstr("OPTIONS:\n");
	ft_putstr("\t-g\t\t- Display only global (external) symbols\n");
	ft_putstr("\t-j\t\t- Just display the symbol names (no value or type)\n");
	ft_putstr("\t-u\t\t- Display only undefined symbols\n");
	ft_putstr("\t-U\t\t- Don't display undefined symbols\n");
	ft_putstr("\t-r\t\t- Sort in reverse order (alphabetically by default)\n");

	return (EXIT_FAILURE);
}

int		ft_usage_otool(void)
{
	ft_putstr("\nUSAGE: ft_otool [options] <input files>\n\n"); 
	ft_putstr("OPTIONS:\n");
	ft_putstr("\t-h\t\t- Print the mach header\n");
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
