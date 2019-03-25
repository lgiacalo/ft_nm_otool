/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/22 20:08:56 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_gestion_symtab_command(void *ptr, struct symtab_command *sym)
{
	uint32_t							i;
	char						*strtable;
	struct nlist_64	*a_64;
	struct nlist		*a;

	i = -1;
	a_64 = (void *)ptr + sym->symoff;
	a = (void *)ptr + sym->symoff;
	strtable = (void *)ptr + sym->stroff;
	while (++i < sym->nsyms)
	{
		if (ft_is_64(env()->magic_mh) && !(a_64[i].n_type & N_STAB))
			ft_gestion_nlist(strtable + a_64[i].n_un.n_strx, a_64[i].n_type, a_64[i].n_sect, a_64[i].n_value);
		else if (!(a[i].n_type & N_STAB))
			ft_gestion_nlist(strtable + a[i].n_un.n_strx, a[i].n_type, a[i].n_sect, a[i].n_value);
	}
}

/*
**	Lecture load command ==> symtab_command
**	* retirer parametre int i !!
*/

void	ft_lc_symtab(struct load_command *lc, int i)
{
	struct symtab_command	*sym;

	sym = (struct symtab_command *)lc;
	ft_fdprintf(FDD, "\n====> Fonction lc symtab \n");
	ft_print_load_command(lc, i);
	ft_print_symtab_cmd(sym);
	// Verification Symbol + String Table !! OK
	if (!ft_is_safe(env()->ptr_mh + sym->symoff, sym->nsyms *
		(ft_is_64(env()->magic_mh) ? sizeof(struct nlist_64) : sizeof(struct nlist))) ||
		!ft_is_safe(env()->ptr_mh + sym->stroff, sym->strsize))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR6));
	ft_gestion_symtab_command(env()->ptr_mh, sym);

//PRINT
	ft_fdprintf(1, "\nFile : %s + %s", env()->file_name, env()->file_name_mh);
	ft_print_lst_line();
	ft_fdprintf(1, "\n");
	env()->line = NULL; //Free list !!!!
}

/*
** Lecture load command ==> segment_command
**	* retirer parametre int i !!
*/

void	ft_lc_segment(struct load_command *lc, int i)
{
	struct segment_command_64	seg;

	if (!ft_record_segment_cmd_64(env()->magic_mh, (void *)lc, &seg))
		return ;
	ft_fdprintf(FDD, "\n====> Fonction lc segment \n");
	ft_print_load_command(lc, i);
	ft_print_segment_cmd_64(&seg);
}

/*
**  Boucle sur toutes les load commands
*/

void ft_load_command(void *ptr, int ncmds)
{
	struct load_command		*lc;
	int                   i;

	i = -1;
	lc = (struct load_command *)ptr;
	while (++i < ncmds)
	{
		if (!ft_is_safe(lc, lc->cmdsize))
			return ft_error_void3(env()->cmd, env()->file_name, ERROR6);
		if (lc->cmd == LC_SEGMENT || lc->cmd == LC_SEGMENT_64)
			ft_lc_segment(lc, i);
		else if (lc->cmd == LC_SYMTAB)
			ft_lc_symtab(lc, i);
		else
			ft_print_load_command(lc, i);
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
	ft_fdprintf(FDD, "Good \n");
}
