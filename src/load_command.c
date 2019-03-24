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

//TODO: A faire fonction pour list t_line
// attention si name == NULL pas de free !

char	*ft_record_name_symbole(char *name)
{
	int	len;
	char	*str;

	len = ft_strlen_nm(name);
	str = ft_strndup(name, len);
	ft_fdprintf(FDD, "Name = %s\n", str);
	return (str);
}

/*
** Fonction a supprimer !! temporaire
**		---> uniquement pour nlist_64 !!!!
*/

void	print_output(char *ptr, int nsyms, int symoff, int stroff)
{
	int							i;
	char						*strtable;
	struct nlist_64	*array;
	t_line					line;

	i = -1;
	array = (void *)ptr + symoff;
	strtable = (void *)ptr + stroff;
	ft_fdprintf(FDD, "Sizeof nlist_64 = %lu\n", sizeof(struct nlist_64));
	ft_fdprintf(FDD, "LC_SYMYAB : stroff = %d / symoff = %d\n\n", stroff, symoff);
	while (++i < nsyms)
	{
		if (!(array[i].n_type & N_STAB))
		{
			line.name = ft_record_name_symbole(strtable + array[i].n_un.n_strx);
			ft_fdprintf(FDD, "%016llx %s\n", array[i].n_value, "name");
			ft_fdprintf(FDD, "\t +%d <= n_strx / i = %d\t / n_type = %#x / n_sect = %d\n\n\n", array[i].n_un.n_strx, i, array[i].n_type, array[i].n_sect);
		}
	}
}

void	ft_gestion_symtab_command(void *ptr, struct symtab_command *sym)
{
	(void)ptr;
	(void)sym;
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
	// ft_gestion_symtab_command(env()->ptr_mh, sym);
	print_output(env()->ptr_mh, sym->nsyms, sym->symoff, sym->stroff);//TODO: a retirer
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
