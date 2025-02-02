/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_nm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:22:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env	*e;
	int		ind;

	e = ft_init_env();
	ind = ft_parse_option(argc, argv, OPT_NM, &(e->opt));
	if (!ind)
		return (ft_usage_nm());
	e->print_name = ft_multi_args(ind, argc);
	if (env()->opt & OPT_U)
		env()->opt |= OPT_J;
	ft_loop_args(argc, argv, ind);
	return (0);
}
