/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:22:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int  main(int argc, char **argv)
{
	ft_printf("---- OTOOL -----\n");
	t_env	*e;
	int		ind;

	e = ft_init_env();
	e->cmd = OTOOL;
	ind = ft_parse_option(argc, argv, OPT_OTOOL, &(e->opt));
	if (!ind || ind == argc)
		return (ft_usage_otool());
	e->print_name = ft_multi_args(ind, argc);
	if (!(env()->opt & OPT_D))
		env()->opt |= OPT_T;
	ft_loop_args(argc, argv, ind);


	return (0);
}
