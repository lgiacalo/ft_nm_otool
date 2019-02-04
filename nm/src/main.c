/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 21:46:46 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print(void)
{
	ft_print_env();
}

void	ft_archive_static(void)
{
	ft_print();
	if (!ft_verif_header_line((void *)((char *)env()->ptr + 8)))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
}

void	ft_reading_file(char *name)
{
	t_env	*e;

	e = env();
	e->file_name = name;
	e->magic = *((uint32_t *)(e->ptr));
	if (ft_is_mh(e->magic))
		return (ft_print());
	else if (ft_is_fat(e->magic))
		return (ft_print());
	else if (ft_is_arc((char *)(e->ptr)))
	{
		e->magic = 0;
		return (ft_archive_static());
	}
	return (ft_error_void3(e->cmd, name, ERROR1));
}

void	ft_loop_args(int argc, char **argv, int ind)
{
	int		fd;
	int		i;
	char	*file;

	i = ind - 1;
	while (++i < argc || ind == argc)
	{
		printf("\n\n--------------------------------------------------\n");
		ft_reinit_env();
		file = (ind == argc) ? "a.out" : argv[i];
		if (ft_open_file(env()->cmd, file, &fd))
		{
			if (ft_check_file(fd, file, env()->cmd, &(env()->file_size)))
			{
				if (ft_mmap_file(fd, env()->file_size, &(env()->ptr)))
				{
					ft_print();
					ft_reading_file(file);
				}
				ft_munmap_file(env()->file_size, &(env()->ptr));
			}
			ft_close_file(env()->cmd, file, fd);
		}
	}
}

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env 	*e;
	int		ind;

	e = ft_init_env();
	ind = ft_parse_option(argc, argv, OPT_NM, &(e->opt));
	if (!ind || ind == argc)
		return (ft_usage_nm());
	e->print_name = ft_multi_args(ind, argc);

	if (env()->opt & OPT_U)
		env()->opt |= OPT_J;

	ft_print_option_nm();
	ft_loop_args(argc, argv, ind);
	return (0);
}
