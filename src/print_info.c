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

void	ft_print_title(void)
{
	t_env	*e;

	e = env();
	if (e->magic == 0)
	{
		ft_fdprintf(1, "\n%s(%s)", e->file_name, e->file_name_mh);
		(e->arch) ? ft_fdprintf(1, ":\n") : ft_fdprintf(1, " (%s)\n", "archi");
	}
	else if (ft_is_fat(e->magic) && !(e->arch))
		ft_fdprintf(1, "\n%s (%s):\n", e->file_name, "archi");
	else if (e->print_name && !ft_is_fat(e->magic))
		ft_fdprintf(1, "\n%s:\n", e->file_name);
}

void 	ft_print_line(t_line *line, int i)
{
	int 	pad;

	pad = ft_is_64(env()->magic_mh) ? 16 : 8;
	if (!line)
		return ;
	if (!(line->addr) && line->sym == 'U')
		ft_fdprintf(1, "%*s %c %s\n", pad, " ", line->sym, line->name);
	else
		ft_fdprintf(1, "%0*llx %c %s\n", pad, line->addr, line->sym, line->name);
	(void)i;
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
	(void)numlc;
}

void 	ft_print_symtab_header(t_symtab_header *sym_h)
{
	// time_t	t;

	if (!sym_h)
		return ;
//	t = ft_atoi(sym_h->date);
	ft_fdprintf(FDD, "Info NM --- SYMTAB HEADER lib.a (Header Line)----\n");
	ft_fdprintf(FDD, "Name:\t\t%s\n", sym_h->name);
//	ft_print_str("Date:\t\t", ctime(&t), "");
	ft_fdprintf(FDD, "User ID:\t%d\n", (sym_h->userId));
	ft_fdprintf(FDD, "Group ID:\t%d\n", (sym_h->groupId));
	ft_fdprintf(FDD, "Mode:\t\t%d\n", (sym_h->mode));
	ft_fdprintf(FDD, "Size:\t\t%d\n", (sym_h->size));
	ft_fdprintf(FDD, "Decalage:\t%d\n", sym_h->next);
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
	ft_fdprintf(FDD, "Date:\t\t%s\n", ctime(&t));
	ft_fdprintf(FDD, "User ID:\t%d\n", ft_atoi((char *)(ptr + 28)));
	ft_fdprintf(FDD, "Group ID:\t%d\n", ft_atoi((char *)(ptr + 34)));
	ft_fdprintf(FDD, "Mode:\t\t%d\n", ft_atoi((char *)(ptr + 40)));
	ft_fdprintf(FDD, "Size:\t\t%d\n", ft_atoi((char *)(ptr + 48)));
	ft_fdprintf(FDD, "End Header:\t  `\\n\n\n");
	ft_fdprintf(FDD, "Header line: \t%s\n\n\n", (char *)ptr);
}


void	ft_print_mach_header_64(struct mach_header_64	*mach_header)
{
	if (!mach_header)
		return ;
	ft_fdprintf(FDD, "Info NM ----- MACH_HEADER_64 ---------\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)mach_header->magic, "\n");
	ft_fdprintf(FDD, "CpuType: \t%d (", mach_header->cputype);
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(mach_header->cputype, mach_header->cpusubtype)->name), ")", "\n");
	ft_print_int16("CpuSubType: \t", (uint16_t)mach_header->cpusubtype, "\n");
	ft_fdprintf(FDD, "File Type: \t%d\n", mach_header->filetype);
	ft_fdprintf(FDD, "Ncmds: \t\t%d\n", mach_header->ncmds);
	ft_fdprintf(FDD, "SizeofCmds: \t%d\n", mach_header->sizeofcmds);
	ft_print_int16("Flags: \t\t", mach_header->flags, "\n\n");
}

void	ft_print_fat_arch_64(struct fat_arch_64 *arch)
{
	if (!arch)
		return ;
	ft_fdprintf(FDD, "\nInfo NM --------------------- FAT_ARCH_64 ---------------------\n");
	ft_fdprintf(FDD, "CpuType: \t%d (", arch->cputype);
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(arch->cputype, arch->cpusubtype)->name), ")", "\n");
	ft_fdprintf(FDD, "CpuSubType: \t%x\n", (uint16_t)arch->cpusubtype);
	ft_fdprintf(FDD, "Offset: \t%d\n", arch->offset);
	ft_fdprintf(FDD, "Size: \t\t%d\n", arch->size);
	ft_fdprintf(FDD, "Align: \t\t2^%d", arch->align);
	ft_fdprintf(FDD, " (%d)\n", ft_power(2, arch->align));
	ft_fdprintf(FDD, "Reserved: \t%d\n\n", arch->reserved);
}

void	ft_print_fat_header(struct fat_header *header)
{
	if (!header)
		return ;
	ft_fdprintf(FDD, "Info NM ----- FAT_HEADER ---------\n");
	ft_print_int16("Magic number: \t", header->magic, "\n");
	ft_fdprintf(FDD, "Nb struct fat_arch: \t%d\n\n", header->nfat_arch);
}

void	ft_print_option_nm(void)
{
	ft_fdprintf(FDD, "Info NM -------- OPTION ---------\n");
	if (!(env()->opt))
	{
		ft_fdprintf(FDD, "Aucune option\n\n");
		return ;
	}
	ft_fdprintf(FDD, "-g:\t%s\n", (env()->opt & OPT_G) ? "Yes" : "No");
	ft_fdprintf(FDD, "-j:\t%s\n", (env()->opt & OPT_J) ? "Yes" : "No");
	ft_fdprintf(FDD, "-u:\t%s\n", (env()->opt & OPT_U) ? "Yes" : "No");
	ft_fdprintf(FDD, "-U:\t%s\n", (env()->opt & OPT_UU) ? "Yes" : "No");
	ft_fdprintf(FDD, "-r:\t%s\n", (env()->opt & OPT_R) ? "Yes" : "No");
	ft_fdprintf(FDD, "Variable opt = %d\n\n", env()->opt);
}

void	ft_print_env(void)
{
	t_env	*e;

	e = env();
	ft_fdprintf(FDD, "Info NM ----- ENV ---------\n");
	ft_fdprintf(FDD, "Cmd: \t\t%s\n", e->cmd);
	ft_fdprintf(FDD, "Print_name: \t%s\n", (e->print_name) ? "yes" : "non");
	ft_fdprintf(FDD, "File_name: \t%s\n", e->file_name);
	ft_fdprintf(FDD, "File_size: \t%d\n", e->file_size);
	ft_print_int16("File_ptr: \t", (unsigned long long int)e->ptr, "\n");
	if (ft_is_arc((char *)(e->ptr)))
		ft_print_str("Magic number: \t%s\n", "archive", "\n");
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
