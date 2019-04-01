/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:06:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 22:34:39 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

size_t	ft_align(size_t nb, size_t modulo)
{
	if ((nb % modulo) == 0)
		return (nb);
	return (((nb / modulo) + 1) * modulo);
}

int		ft_usage_nm(void)
{
	ft_printf("\nUSAGE: ft_nm [options] <input files>\n\n");
	ft_printf("OPTIONS:\n");
	ft_printf("\t-g\t\t- Display only global (external) symbols\n");
	ft_printf("\t-j\t\t- Just display the symbol names (no value or type)\n");
	ft_printf("\t-u\t\t- Display only undefined symbols\n");
	ft_printf("\t-U\t\t- Don't display undefined symbols\n");
	ft_printf("\t-r\t\t- Sort in reverse order (alphabetically by default)\n");
	ft_printf("\t-a\t\t- Display all arch\n");
	return (EXIT_FAILUR);
}

int		ft_usage_otool(void)
{
	ft_printf("\nUSAGE: ft_otool [options] <input files>\n\n");
	ft_printf("OPTIONS:\n");
	ft_printf("\t-t\t\t- Print the text section\n");
	ft_printf("\t-d\t\t- Print the data section\n");
	ft_printf("\t-m\t\t- Display like print memory\n");
	return (EXIT_FAILUR);
}
