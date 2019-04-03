/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_nm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/04/03 20:39:26 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include "ft_otool.h"

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
	env()->dec = 0;
	ft_reinit_sym();
	size_struct = ft_is_64(magic_mh)
	? sizeof(struct mach_header_64) : sizeof(struct mach_header);
	if (!ft_record_mach_header_64(magic_mh, ptr, &mach_header))
		return ;
	if (!ft_is_safe(ptr + size_struct, mach_header.sizeofcmds))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR6));
	if (!ft_strcmp(env()->cmd, NM))
		ft_load_command_nm(ptr + size_struct, mach_header.ncmds);
	else
		ft_load_command_otool(ptr + size_struct, mach_header.ncmds);
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
	e->symbol.b = 0;
	e->magic = *((uint32_t *)(e->ptr));
	if (ft_is_mh(e->magic))
		ft_mach_header_64(e->ptr, e->magic);
	else if (ft_is_fat(e->magic))
		ft_fatbinary((e->opt & OPT_A) ? 1 : 0);
	else if (ft_is_arc((char *)(e->ptr)))
	{
		e->magic = 0;
		ft_archive_static(e->ptr, e->file_size);
	}
	else
	{
		if (!ft_strcmp(e->cmd, OTOOL))
			ft_error_void3(name, ": is not an object file", "");
		else
			ft_error_void3(e->cmd, name, ERROR1);
	}
	ft_munmap_file(env()->file_size, &(env()->ptr));
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
	while (++i < argc || i == argc)
	{
		ft_reinit_env();
		env()->p_archive = 0;
		env()->symbol.b = 1;
		file = (ind == argc) ? "a.out" : argv[i];
		if (ft_open_file(env()->cmd, file, &fd))
		{
			if (ft_check_file(fd, file, env()->cmd, &(env()->file_size)))
			{
				if (ft_mmap_file(fd, env()->file_size, &(env()->ptr)))
					ft_reading_file(file);
			}
			ft_close_file(env()->cmd, file, fd);
		}
		if (env()->symbol.b && !ft_strcmp(env()->cmd, OTOOL))
			return ;
	}
}
