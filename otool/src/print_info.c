/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:47:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 15:41:05 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_print_option_otool(void)
{
	ft_putstr("Info OTOOL - Option\n");
	if (!(env()->opt))
	{
		ft_putstr("Aucune option\n");
		return ;
	}
	ft_print_str("-h:\t", (env()->opt & OPT_H) ? "Yes" : "No", "\n");
	ft_print_str("-t:\t", (env()->opt & OPT_T) ? "Yes" : "No", "\n");
	ft_print_str("-d:\t", (env()->opt & OPT_D) ? "Yes" : "No", "\n");
	ft_print_int("Variable opt = ", env()->opt, "\n");
}
