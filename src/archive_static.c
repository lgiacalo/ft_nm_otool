/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 18:55:26 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**  File archive static X.a
**		Faire verif et envoyer a ft_mach_header_64
**		Boucle pour envoyer tous les .o
*/

void	ft_archive_static(void *ptr, int max)
{
	t_symtab_header	sym_h;
	void			*tp;

	if (!ft_record_symtab_header(&sym_h, ptr + 8) &&
			!ft_is_safe(ptr + 68, sym_h.size))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
	env()->magic = 0;
	tp = ptr + 68 + sym_h.size;
	while (tp < (ptr + max))
	{
		if (!ft_record_symtab_header(&sym_h, tp) ||
				!ft_is_safe(tp + 60, sym_h.size))
			return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
		ft_mach_header_64((tp + sym_h.next), *((uint32_t *)(tp + sym_h.next)));
		tp = tp + 60 + sym_h.size;
	}
	if (tp != (ptr + max))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
}
