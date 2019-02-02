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
