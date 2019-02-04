/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 21:50:22 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

/*
** Commande OTOOL
*/

int		main(int argc, char **argv)
{
	t_env	*e;

	printf("Debut projet OTOOL\n");
	e = ft_init_env();
	if (!ft_parse_option(argc, argv, OPT_OTOOL, &(env()->opt)))
		return (ft_usage_otool());
	ft_print_option_otool();
	return (0);
}
