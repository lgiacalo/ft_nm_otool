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

int	ft_gestion_symtab_command(void *ptr, struct symtab_command *sym)
{
	uint32_t							i;
	int 									out;
	char						*strtable;
	struct nlist_64	*a_64;
	struct nlist		*a;

	i = -1;
	out = 1;
	a_64 = (void *)ptr + sym->symoff;
	a = (void *)ptr + sym->symoff;
	strtable = (void *)ptr + sym->stroff;
	while (++i < sym->nsyms)
	{
		if (ft_is_64(env()->magic_mh) && !(a_64[i].n_type & N_STAB))
			out = ft_gestion_nlist(strtable + a_64[i].n_un.n_strx, a_64[i].n_type,
				a_64[i].n_sect, a_64[i].n_value);
		else if (!(a[i].n_type & N_STAB))
			out = ft_gestion_nlist(strtable + a[i].n_un.n_strx, a[i].n_type,
				a[i].n_sect, a[i].n_value);
		if (!out)
			return (EXIT_FAILUR);
	}
	return (EXIT_SUCCES);
}

/*
**	Lecture load command ==> symtab_command
**	* retirer parametre int i !!
*/

int	ft_lc_symtab(struct load_command *lc)
{
	struct symtab_command	*sym;

	sym = (struct symtab_command *)lc;
	if (!ft_is_safe(env()->ptr_mh + sym->symoff, sym->nsyms *
		(ft_is_64(env()->magic_mh) ? sizeof(struct nlist_64) : sizeof(struct nlist))) ||
		!ft_is_safe(env()->ptr_mh + sym->stroff, sym->strsize))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	if (!ft_gestion_symtab_command(env()->ptr_mh, sym))
		return (EXIT_FAILUR);

	ft_fdprintf(1, "\nFile : %s + %s", env()->file_name, env()->file_name_mh);
	ft_print_lst_line();
	ft_fdprintf(1, "\n");
	env()->line = NULL; //TODO: Free list !!!!
	return (EXIT_SUCCES);
}

/*
** Lecture load command ==> segment_command
*/

void	ft_lc_segment_nm(struct load_command *lc)
{
	struct segment_command_64	seg;
	char 											*str;
	int												k;
	int 											st;

	k = 0;
	st = ft_is_64(env()->magic_mh);
	if (!ft_record_segment_cmd_64(env()->magic_mh, (void *)lc, &seg) ||
		seg.nsects == 0)
		return ;
	while ((uint32_t)k < seg.nsects)
	{
		(env()->dec)++;
		str = (char *)(((void *)lc + (st ? sizeof(struct segment_command_64) :
		sizeof(struct segment_command))) + (k * (st ? sizeof(struct section_64) :
		sizeof(struct section))));
		if (!ft_strcmp("__text", str))
			env()->symbol.t = env()->dec;
		else if (!ft_strcmp("__data", str))
			env()->symbol.d = env()->dec;
		else if (!ft_strcmp("__bss", str))
			env()->symbol.b = env()->dec;
		k++;
	}
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
			ft_lc_segment_nm(lc);
		if (lc->cmd == LC_SYMTAB)
			if (!ft_lc_symtab(lc))
				return ;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}
