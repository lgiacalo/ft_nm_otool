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

void 	ft_print_line(t_line *line, int i)
{
	if (!line)
		return ;
	ft_fdprintf(FDD, "\nInfo NM --- LINE n%d ---\n", i);
	if (!(line->addr) && line->sym == 'U')
		ft_fdprintf(1, "%*16s %c %s\n", 16, " ", line->sym, line->name);
	else
		ft_fdprintf(1, "%016llx %c %s\n", line->addr, line->sym, line->name);
}

void	ft_print_symtab_cmd(struct symtab_command *sym)
{
	if (!sym || sym->cmd != LC_SYMTAB)
		return ;
	ft_fdprintf(FDD, "Info NM ----- SYMTAB COMMAND ---------\n");
	ft_fdprintf(FDD, "Cmd:\t\t%s\n", "LC_SYMTAB");
	ft_fdprintf(FDD, "Cmdsize:\t%d\n", sym->cmdsize);
	ft_fdprintf(FDD, "SymOff:\t\t%d\n", sym->symoff);
	ft_fdprintf(FDD, "Nsyms:\t\t%d\n", sym->nsyms);
	ft_fdprintf(FDD, "StrOff:\t\t%d\n", sym->stroff);
	ft_fdprintf(FDD, "StrSize:\t%d\n\n\n", sym->strsize);
}

void	ft_print_segment_cmd_64(struct segment_command_64 *seg)
{
	if (!seg)
		return ;
	ft_fdprintf(FDD, "Info NM ----- SEGMENT_COMMAND_64 ---------\n");
	ft_fdprintf(FDD, "Cmd:\t\t%s\n", (seg->cmd == LC_SEGMENT ? "LC_SEGMENT" : "LC_SEGMENT_64"));
	ft_fdprintf(FDD, "Cmdsize:\t%d\n", seg->cmdsize);
	ft_fdprintf(FDD, "Segname:\t%s\n", seg->segname);
	ft_fdprintf(FDD, "VmAddr:\t\t%d\n", seg->vmaddr);
	ft_fdprintf(FDD, "VmSize:\t\t%d\n", seg->vmsize);
	ft_fdprintf(FDD, "FileOff:\t%d\n", seg->fileoff);
	ft_fdprintf(FDD, "FileSize:\t%d\n", seg->filesize);
	ft_fdprintf(FDD, "MaxProt:\t%d\n", seg->maxprot);
	ft_fdprintf(FDD, "InitProt:\t%d\n", seg->initprot);
	ft_fdprintf(FDD, "NSects:\t\t%d\n", seg->nsects);
	ft_fdprintf(FDD, "Flags:\t\t%d\n\n\n", seg->flags);
}

void	ft_print_load_command(struct load_command *lc, int numlc)
{
	if (!lc)
		return ;
	ft_fdprintf(FDD, "Info NM ----- LOAD_COMMAND n%d ---------\n", numlc);
	ft_fdprintf(FDD, "Cmd:\t\t%d\n", (lc->cmd));
	ft_fdprintf(FDD, "Cmdsize:\t%d\n\n", lc->cmdsize);
}

void 	ft_print_symtab_header(t_symtab_header *sym_h)
{
	// time_t	t;

	if (!sym_h)
		return ;
//	t = ft_atoi(sym_h->date);
	ft_fdprintf(FDD, "Info NM --- SYMTAB HEADER lib.a (Header Line)----\n");
	ft_print_str("Name:\t\t", sym_h->name, "\n");
//	ft_print_str("Date:\t\t", ctime(&t), "");
	ft_print_int("User ID:\t", (sym_h->userId), "\n");
	ft_print_int("Group ID:\t", (sym_h->groupId), "\n");
	ft_print_int("Mode:\t\t", (sym_h->mode), "\n");
	ft_print_int("Size:\t\t", (sym_h->size), "\n");
	ft_print_int("Decalage:\t", sym_h->next, "\n");
	ft_fdprintf(FDD, "End Header:\t  `\\n\n\n");
}

/*
** Sans la structure t_symtab_header *
*/

void 	ft_print_symtab_header2(void *ptr)
{
	time_t	t;

	if (!ptr)
		return ;
	t = (ft_atoi((char *)(ptr + 16)));
	ft_fdprintf(FDD, "Info NM --- SYMTAB HEADER lib.a (Header Line)----\n");
	if (*(char *)ptr == '#')
		ft_fdprintf(FDD, "Name:\t\t", (char *)(ptr + 60), "\n");
	else
		ft_fdprintf(FDD, "Name:\t\t", (char *)ptr, "\n");
	ft_print_str("Date:\t\t", ctime(&t), "");
	ft_print_int("User ID:\t", ft_atoi((char *)(ptr + 28)), "\n");
	ft_print_int("Group ID:\t", ft_atoi((char *)(ptr + 34)), "\n");
	ft_print_int("Mode:\t\t", ft_atoi((char *)(ptr + 40)), "\n");
	ft_print_int("Size:\t\t", ft_atoi((char *)(ptr + 48)), "\n");
	ft_fdprintf(FDD, "End Header:\t  `\\n\n\n");
	ft_print_str("Header line: \t", (char *)ptr, "\n\n");
}


void	ft_print_mach_header_64(struct mach_header_64	*mach_header)
{
	if (!mach_header)
		return ;
	ft_fdprintf(FDD, "Info NM ----- MACH_HEADER_64 ---------\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)mach_header->magic, "\n");
	ft_print_int("CpuType: \t", mach_header->cputype, " (");
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(mach_header->cputype, mach_header->cpusubtype)->name), ")", "\n");
	ft_print_int16("CpuSubType: \t", (uint16_t)mach_header->cpusubtype, "\n");
	ft_print_int("File Type: \t", mach_header->filetype, "\n");
	ft_print_int("Ncmds: \t\t", mach_header->ncmds, "\n");
	ft_print_int("SizeofCmds: \t", mach_header->sizeofcmds, "\n");
	ft_print_int16("Flags: \t\t", mach_header->flags, "\n\n");
}

void	ft_print_fat_arch_64(struct fat_arch_64 *arch)
{
	if (!arch)
		return ;
	ft_fdprintf(FDD, "\nInfo NM --------------------- FAT_ARCH_64 ---------------------\n");
	ft_print_int("CpuType: \t", arch->cputype, " (");
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(arch->cputype, arch->cpusubtype)->name), ")", "\n");
	ft_print_int16("CpuSubType: \t", (uint16_t)arch->cpusubtype, "\n");
	ft_print_int("Offset: \t", arch->offset, "\n");
	ft_print_int("Size: \t\t", arch->size, "\n");
	ft_print_int("Align: \t\t2^", arch->align, "");
	ft_print_int(" (", ft_power(2, arch->align), ")\n");
	ft_print_int("Reserved: \t", arch->reserved, "\n\n");
}

void	ft_print_fat_header(struct fat_header *header)
{
	if (!header)
		return ;
	ft_fdprintf(FDD, "Info NM ----- FAT_HEADER ---------\n");
	ft_print_int16("Magic number: \t", header->magic, "\n");
	ft_print_int("Nb struct fat_arch: \t", header->nfat_arch, "\n\n");
}

void	ft_print_option_nm(void)
{
	ft_fdprintf(FDD, "Info NM -------- OPTION ---------\n");
	if (!(env()->opt))
	{
		ft_fdprintf(FDD, "Aucune option\n\n");
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

	ft_fdprintf(FDD, "Valeur fd = %d\n", FDD);

	e = env();
	ft_fdprintf(FDD, "Info NM ----- ENV ---------\n");
	ft_print_str("Cmd: \t\t", e->cmd, "\n");
	ft_print_str("Print_name: \t", (e->print_name) ? "yes" : "non", "\n");
	ft_print_str("File_name: \t", e->file_name, "\n");
	ft_print_int("File_size: \t", e->file_size, "\n");
	ft_print_int16("File_ptr: \t", (unsigned long long int)e->ptr, "\n");
	if (ft_is_arc((char *)(e->ptr)))
		ft_print_str("Magic number: \t", "archive", "\n");
	else
		ft_print_int16("Magic number: \t", (unsigned long long int)(e->magic), "\n");
	ft_print_int16("Magic_mh number: \t", (unsigned long long int)(e->magic_mh), "\n");
	ft_fdprintf(FDD, "Swap: \t\t%d\n\n", e->swap);
}

void	ft_print_file(void)
{
	t_env	*e;

	e = env();
	ft_fdprintf(FDD, "Info NM --- PRINT FILE ------\n");
	print_memory(e->ptr, e->file_size);
	ft_fdprintf(FDD, "\n");
}
