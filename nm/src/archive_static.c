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
*/

void	ft_archive_static(void *ptr)
{
	t_symtab_header	sym_h;

	if (!ft_record_symtab_header(&sym_h, ptr + 8))
		return ;
	ft_print_symtab_header(&sym_h);


	// ft_print_symtab_header2((ptr + 68 + sym_h.size));
//	ft_print_mach_header_64();
}
