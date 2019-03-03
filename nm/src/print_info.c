/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:47:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:32:25 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print_fat_arch_64(struct fat_arch_64 *arch)
{
	if (!arch)
		return ;
	ft_putstr("Info NM ----- FAT_ARCH_64 ---------\n");
	ft_print_int("CpuType: \t", arch->cputype, "\n");
	ft_print_int16("CpuSubType: \t", (uint16_t)arch->cpusubtype, "(");
	ft_print_str(ft_get_name_cpu(arch->cputype, (uint16_t)arch->cpusubtype), ")", "\n");
	ft_print_int("Offset: \t", arch->offset, "\n");
	ft_print_int("Size: \t\t", arch->size, "\n");
	ft_print_int("Align: \t\t", ft_power(2, arch->align), " (2^");
	ft_print_int("", arch->align, ")\n");
	ft_print_int("Reserved: \t", arch->reserved, "\n\n");
}

void	ft_print_fat_header(struct fat_header *header)
{
	if (!header)
		return ;
	ft_putstr("Info NM ----- FAT_HEADER ---------\n");
	ft_print_int16("Magic number: \t", header->magic, "\n");
	ft_print_int("Nb struct fat_arch: \t", header->nfat_arch, "\n\n");
}

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
	ft_print_int16("Magic number: \t", (unsigned long long int)
			((uint32_t)*((uint32_t*)(e->ptr))), "\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)(e->magic),
			"\n\n");
}

void	ft_print_file(void)
{
	t_env	*e;

	e = env();
	ft_putstr("Info NM --- PRINT FILE ------\n");
	print_memory(e->ptr, e->file_size);
	ft_putstr("\n");
}
