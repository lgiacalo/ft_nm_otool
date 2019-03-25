/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:22:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**	Fichier object :
**		Copie struct mach_header avec swap si nec
**		Call ft_load_command with ncomds lc
**		Verif size to load command safe
*/

void	ft_mach_header_64(void *ptr, uint32_t magic_mh)
{
	struct mach_header_64	mach_header;
	size_t					size_struct;

	env()->magic_mh = magic_mh;
	env()->ptr_mh = ptr;
	size_struct = ft_is_64(magic_mh) ? sizeof(struct mach_header_64)
	: sizeof(struct mach_header);
	if (!ft_record_mach_header_64(magic_mh, ptr, &mach_header))
		return ;
	if (!ft_is_safe(ptr + size_struct, mach_header.sizeofcmds))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR6));
	ft_load_command(ptr + size_struct, mach_header.ncmds);
}

/*
**	Lecture file
**		upd env : file_name + magic + swap
**		redirection file selon type (fat, archive, obj)
*/

void	ft_reading_file(char *name)
{
	t_env	*e;

	e = env();
	e->file_name = name;
	e->magic = *((uint32_t *)(e->ptr));
	e->swap = ft_is_swap(e->magic);
	if (ft_is_mh(e->magic))
		return (ft_mach_header_64(e->ptr, e->magic));
	else if (ft_is_fat(e->magic))
		return (ft_fatbinary(0));
	else if (ft_is_arc((char *)(e->ptr)))
	{
		e->magic = 0;
		return (ft_archive_static(e->ptr, e->file_size));
	}
	return (ft_error_void3(e->cmd, name, ERROR1));
}

/*
**	Boucle sur tous les arguments	avec verif + enregistrement du fichier
**		struct env reinit a chaque tour
**		update env : file_size + ptr
*/

void	ft_loop_args(int argc, char **argv, int ind)
{
	int		fd;
	int		i;
	char	*file;

	i = ind - 1;
	while (++i < argc || ind == argc)
	{
		ft_reinit_env();
		file = (ind == argc) ? "a.out" : argv[i];
		if (ft_open_file(env()->cmd, file, &fd))
		{
			if (ft_check_file(fd, file, env()->cmd, &(env()->file_size)))
			{
				if (ft_mmap_file(fd, env()->file_size, &(env()->ptr)))
				{
					ft_reading_file(file);
					ft_munmap_file(env()->file_size, &(env()->ptr));
				}
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
	t_env	*e;
	int		ind;

	fichier(); //TODO: a retirer
	e = ft_init_env();
	ind = ft_parse_option(argc, argv, OPT_NM, &(e->opt));
	if (!ind || ind == argc)
		return (ft_usage_nm());
	e->print_name = ft_multi_args(ind, argc);
	if (env()->opt & OPT_U)
		env()->opt |= OPT_J;
	ft_loop_args(argc, argv, ind);
	return (0);
}

void	fichier(void)
{
	if ((FDD = open("log", O_RDWR | O_CREAT | O_APPEND)) == -1)
		FDD = 1;
}
