/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/03 19:58:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print()
{
	ft_print_env();
	ft_print_file();
}

void	ft_start_nm(char *name)
{
	t_env	*e;

	e = env();
	e->file_name = name;
}

void	ft_loop_args(int argc, char **argv, int ind)
{
	int	fd;

	while (ind < argc)
	{
		if (ft_open_file(NM, argv[ind], &fd))
		{
			if (ft_check_file(fd, argv[ind], NM, &(env()->fstat_size)))
			{
				if (ft_mmap_file(fd, env()->fstat_size, &(env()->ptr)))
					ft_start_nm(argv[ind]);
				ft_print();
				ft_munmap_file(env()->fstat_size, &(env()->ptr));
			}
			ft_close_file(NM, argv[ind], fd);
		}
		ind++;
	}
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
