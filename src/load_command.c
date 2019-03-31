/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:21:06 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_gestion_nlist(void *array, char *strtable, int i)
{
	int				out;
	uint8_t			swap;
	struct nlist	*a;
	struct nlist_64	*a_64;

	swap = ft_is_swap(env()->magic_mh);
	a = (struct nlist *)array;
	a_64 = (struct nlist_64 *)array;
	if (ft_is_64(env()->magic_mh))
		out = ft_nlist(strtable + (swap ? OSSwapInt32(a_64[i].n_un.n_strx) : a_64[i].n_un.n_strx),
		 a_64[i].n_type, a_64[i].n_sect, (swap ? OSSwapInt64(a_64[i].n_value) : a_64[i].n_value));
	else
		out = ft_nlist(strtable + (swap ? OSSwapInt32(a[i].n_un.n_strx) : a[i].n_un.n_strx),
			a[i].n_type, a[i].n_sect, (swap ? OSSwapInt32(a[i].n_value) : a[i].n_value));
	return (out);
}

int		ft_gestion_symtab_command(struct nlist_64 *a_64, char *strtable,
		struct symtab_command *sym)
{
	uint32_t		i;
	struct nlist	*a;

	i = -1;
	a = (void *)a_64;
	while (++i < sym->nsyms)
	{
		if ((!(a[i].n_type & N_STAB) && !ft_is_64(env()->magic_mh)) ||
			(!(a_64[i].n_type & N_STAB) && ft_is_64(env()->magic_mh)))
		{
			if (!(ft_gestion_nlist((void *)a_64, strtable, i)))
				return (EXIT_FAILUR);
		}
	}
	return (EXIT_SUCCES);
}

/*
**	Lecture load command ==> symtab_command
**	* retirer parametre int i !!
*/

int		ft_lc_symtab(void *ptr, struct load_command *lc)
{
	struct symtab_command	sym;

	if (!ft_record_symtab_command(env()->magic_mh, ptr, &sym, lc->cmdsize))
		return (EXIT_FAILUR);
	if (!ft_is_safe(env()->ptr_mh + sym.symoff, sym.nsyms *
		(ft_is_64(env()->magic_mh) ? sizeof(struct nlist_64) :
		sizeof(struct nlist))) ||
		!ft_is_safe(env()->ptr_mh + sym.stroff, sym.strsize))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	if (!ft_gestion_symtab_command(env()->ptr_mh + sym.symoff,
		env()->ptr_mh + sym.stroff, &sym))
		return (EXIT_FAILUR);
	return (EXIT_SUCCES);
}

/*
** Lecture load command ==> segment_command
*/

void	ft_lc_segment_nm(void *ptr, struct load_command *lc)
{
	struct segment_command_64	seg;
	char						*str;
	int							k;
	int							st;

	(void)lc;
	k = 0;
	st = ft_is_64(env()->magic_mh);
	if (!ft_record_segment_cmd_64(env()->magic_mh, ptr, &seg, lc->cmdsize) ||
		seg.nsects == 0)
		return ;
	while ((uint32_t)k < seg.nsects)
	{
		(env()->dec)++;
		str = (char *)(((char *)ptr + (st ? sizeof(struct segment_command_64) :
		sizeof(struct segment_command))) + (k * (st ?
		sizeof(struct section_64) : sizeof(struct section))));
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

void	ft_load_command(void *ptr, int ncmds)
{
	struct load_command	lc;
	void	*tmp;
	int					i;

	i = -1;
	tmp = ptr;
	ft_reinit_sym();
	while (++i < ncmds)
	{
		if (!ft_record_load_command(env()->magic_mh, tmp, &lc))
			return ;
		if (!ft_is_safe(tmp, lc.cmdsize))
			return (ft_error_void3(env()->cmd, env()->file_name, ERROR6));
		if (lc.cmd == LC_SEGMENT || lc.cmd == LC_SEGMENT_64)
			ft_lc_segment_nm(tmp, &lc);
		if (lc.cmd == LC_SYMTAB)
			if (!ft_lc_symtab(tmp, &lc))
				return ;
		tmp = (struct load_command *)((char *)tmp + lc.cmdsize);
	}
	ft_print_title();
	if (ncmds == 0)
		return ;
	ft_print_lst_line();
	ft_free();
}
