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
		ft_print_load_command(lc, i);
		if (!ft_is_safe(lc, lc->cmdsize))
			return ft_error_void3(env()->cmd, env()->file_name, ERROR6);
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
	ft_fdprintf(FDD, "Good \n");
}
