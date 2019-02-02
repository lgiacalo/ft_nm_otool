/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:47:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 18:42:48 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print_option_nm(void)
{
	ft_putstr("Info NM - Option\n");
	if (!(env()->opt))
	{
		ft_putstr("Aucune option\n");
		return ;
	}
	ft_print_str("-g:\t", (env()->opt & OPT_G) ? "Yes" : "No", "\n");
	ft_print_str("-j:\t", (env()->opt & OPT_J) ? "Yes" : "No", "\n");
	ft_print_str("-u:\t", (env()->opt & OPT_U) ? "Yes" : "No", "\n");
	ft_print_str("-U:\t", (env()->opt & OPT_UU) ? "Yes" : "No", "\n");
	ft_print_str("-r:\t", (env()->opt & OPT_R) ? "Yes" : "No", "\n");
	ft_print_int("Variable opt = ", env()->opt, "\n");
}
