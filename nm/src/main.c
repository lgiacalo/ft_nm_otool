/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 22:51:55 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_start_nm(char *name)
{
	t_env	*e;

	e = env();
	e->file_name = name;
	ft_print_env();
}

void	ft_loop_args(int argc, char **argv, int ind)
{
	int	fd;

	while (ind < argc)
	{
		if ((fd = open(argv[ind], O_RDONLY)) < 0)
			ft_error_int3(NM, argv[ind], ERROR2);
		else
		{
			if (ft_check_file(fd, argv[ind], NM, &(env()->fstat_size)))
			{
				//mmap avec fd !!
				ft_start_nm(argv[ind]);
			}
			if (close(fd) < 0)
				ft_error_void(argv[ind]);
		}
		ind++;
	}
	return ;
}

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env 	*e;
	int		ind;

	printf("Debut projet NM\n");

	e = ft_init_env();
	ind = ft_parse_option(argc, argv, OPT_NM, &(e->opt));
	if (!ind || ind == argc)
		return (ft_usage_nm());

	if (env()->opt & OPT_U)
		env()->opt |= OPT_J;

	ft_print_option_nm();
	ft_loop_args(argc, argv, ind);
	return (0);
}
