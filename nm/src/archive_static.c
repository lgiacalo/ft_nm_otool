/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:45:36 by lgiacalo         ###   ########.fr       */
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
	void						*tmp;

	if (!ft_record_symtab_header(&sym_h, ptr + 8) && !ft_is_safe(ptr + 68, sym_h.size))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
	printf("Max size archive : %d\n\n", max);
	ft_print_symtab_header(&sym_h);
	tmp = ptr + 68 + sym_h.size;
	while (tmp < (ptr + max))
	{
		printf("\n\n------------------------------ BOUCLE ARCHIVE .O -------------------------\n");
		printf("Valeur tmp = %ld\n", (ptr + max - tmp));
		if (!ft_record_symtab_header(&sym_h, tmp))
			return ; // TODO: ajouter erreur ou dans la fonction ft_record_symtab_header
		ft_print_symtab_header(&sym_h);
		if (!ft_is_safe(tmp + 60, sym_h.size))
			return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
		ft_print_mach_header_64((struct mach_header_64 *)((char *)tmp + sym_h.next));
		//TODO: envoyer a ft_mach_header_64 !!
		tmp = tmp + 60 + sym_h.size;
	}
	if (tmp != (ptr + max))
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR3));
}
