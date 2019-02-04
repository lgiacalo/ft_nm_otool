/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:47:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 18:37:39 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print_option_nm(void)
{
	ft_putstr("Info NM ---- OPTION -------\n");
	if (!(env()->opt))
	{
		ft_putstr("Aucune option\n\n");
		return ;
	}
	ft_print_str("-g:\t", (env()->opt & OPT_G) ? "Yes" : "No", "\n");
	ft_print_str("-j:\t", (env()->opt & OPT_J) ? "Yes" : "No", "\n");
	ft_print_str("-u:\t", (env()->opt & OPT_U) ? "Yes" : "No", "\n");
	ft_print_str("-U:\t", (env()->opt & OPT_UU) ? "Yes" : "No", "\n");
	ft_print_str("-r:\t", (env()->opt & OPT_R) ? "Yes" : "No", "\n");
	ft_print_int("Variable opt = ", env()->opt, "\n\n");
}

void	ft_print_env(void)
{
	t_env	*e;

	e = env();
	ft_putstr("Info NM ----- ENV ---------\n");
	ft_print_str("Cmd: \t", e->cmd, "\n");
	ft_print_str("Print_name: \t", (e->print_name) ? "yes" : "non", "\n");
	ft_print_str("File_name: \t", e->file_name, "\n");
	ft_print_int("File_size: \t", e->file_size, "\n");
	ft_print_int16("File_ptr: \t", (unsigned long long int)e->ptr, "\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)((uint32_t)*((uint32_t*)(e->ptr))), "\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)(e->magic), "\n\n");
}

void	ft_print_file(void)
{
	t_env	*e;

	e = env();
	ft_putstr("Info NM --- PRINT FILE ------\n");
	print_memory(e->ptr, e->file_size);
	ft_putstr("\n");
}
