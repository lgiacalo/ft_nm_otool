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

void	ft_lc_segment(struct load_command *lc, int i)
{
	struct segment_command_64	seg;

	if (!ft_record_segment_cmd_64(env()->magic_mh, (void *)lc, &seg))
		return ;
	ft_fdprintf(FDD, "\n====> Fonction lc segment \n");
	ft_print_load_command(lc, i);
	ft_print_segment_cmd_64(&seg);
}

void	ft_lc_symtab(struct load_command *lc, int i)
{
	ft_fdprintf(FDD, "\n====> Fonction lc symtab \n");
	ft_print_load_command(lc, i);
	ft_print_symtab_cmd((struct symtab_command *)lc);
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
		else
			ft_print_load_command(lc, i);
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
	ft_fdprintf(FDD, "Good \n");
}
