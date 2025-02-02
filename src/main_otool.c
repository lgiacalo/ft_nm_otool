/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/04/03 20:43:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	main(int argc, char **argv)
{
	t_env	*e;
	int		ind;

	e = ft_init_env();
	e->cmd = OTOOL;
	ind = ft_parse_option(argc, argv, OPT_OTOOL, &(e->opt));
	if (!ind || ind == argc)
		return (ft_usage_otool());
	e->print_name = 1;
	if (!(env()->opt & OPT_D))
		env()->opt |= OPT_T;
	ft_loop_args(argc, argv, ind);
	return (0);
}
