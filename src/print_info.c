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
		ft_printf("\n%s(%s)", e->file_name, e->file_name_mh);
		(e->arch) ? ft_printf(":\n") : ft_printf(" (%s)\n", "archi");
	}
	else if (ft_is_fat(e->magic) && !(e->arch))
		ft_printf("\n%s (%s):\n", e->file_name, "archi");
	else if (e->print_name && !ft_is_fat(e->magic))
		ft_printf("\n%s:\n", e->file_name);
}

void 	ft_print_line(t_line *line, int i)
{
	int 	pad;

	pad = ft_is_64(env()->magic_mh) ? 16 : 8;
	if (!line)
		return ;
	if (!(line->addr) && line->sym == 'U')
		ft_printf("%*s %c %s\n", pad, " ", line->sym, line->name);
	else
		ft_printf("%0*llx %c %s\n", pad, line->addr, line->sym, line->name);
	(void)i;
}

void	ft_print_symtab_cmd(struct symtab_command *sym)
{
	if (!sym || sym->cmd != LC_SYMTAB)
		return ;
	ft_printf("Info NM ----- SYMTAB COMMAND ---------\n");
	ft_printf("Cmd:\t\t%s\n", "LC_SYMTAB");
	ft_printf("Cmdsize:\t%d\n", sym->cmdsize);
	ft_printf("SymOff:\t\t%d\n", sym->symoff);
	ft_printf("Nsyms:\t\t%d\n", sym->nsyms);
	ft_printf("StrOff:\t\t%d\n", sym->stroff);
	ft_printf("StrSize:\t%d\n\n\n", sym->strsize);
}

void	ft_print_segment_cmd_64(struct segment_command_64 *seg)
{
	if (!seg)
		return ;
	ft_printf("Info NM ----- SEGMENT_COMMAND_64 ---------\n");
	ft_printf("Cmd:\t\t%s\n", (seg->cmd == LC_SEGMENT ? "LC_SEGMENT" : "LC_SEGMENT_64"));
	ft_printf("Cmdsize:\t%d\n", seg->cmdsize);
	ft_printf("Segname:\t%s\n", seg->segname);
	ft_printf("VmAddr:\t\t%d\n", seg->vmaddr);
	ft_printf("VmSize:\t\t%d\n", seg->vmsize);
	ft_printf("FileOff:\t%d\n", seg->fileoff);
	ft_printf("FileSize:\t%d\n", seg->filesize);
	ft_printf("MaxProt:\t%d\n", seg->maxprot);
	ft_printf("InitProt:\t%d\n", seg->initprot);
	ft_printf("NSects:\t\t%d\n", seg->nsects);
	ft_printf("Flags:\t\t%d\n\n\n", seg->flags);
}

void	ft_print_load_command(struct load_command *lc, int numlc)
{
	if (!lc)
		return ;
	ft_printf("Info NM ----- LOAD_COMMAND n%d ---------\n", numlc);
	ft_printf("Cmd:\t\t%d\n", (lc->cmd));
	ft_printf("Cmdsize:\t%d\n\n", lc->cmdsize);
	(void)numlc;
}

void 	ft_print_symtab_header(t_symtab_header *sym_h)
{
	// time_t	t;

	if (!sym_h)
		return ;
//	t = ft_atoi(sym_h->date);
	ft_printf("Info NM --- SYMTAB HEADER lib.a (Header Line)----\n");
	ft_printf("Name:\t\t%s\n", sym_h->name);
//	ft_print_str("Date:\t\t", ctime(&t), "");
	ft_printf("User ID:\t%d\n", (sym_h->userId));
	ft_printf("Group ID:\t%d\n", (sym_h->groupId));
	ft_printf("Mode:\t\t%d\n", (sym_h->mode));
	ft_printf("Size:\t\t%d\n", (sym_h->size));
	ft_printf("Decalage:\t%d\n", sym_h->next);
	ft_printf("End Header:\t  `\\n\n\n");
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
	ft_printf("Info NM --- SYMTAB HEADER lib.a (Header Line)----\n");
	if (*(char *)ptr == '#')
		ft_printf("Name:\t\t", (char *)(ptr + 60), "\n");
	else
		ft_printf("Name:\t\t", (char *)ptr, "\n");
	ft_printf("Date:\t\t%s\n", ctime(&t));
	ft_printf("User ID:\t%d\n", ft_atoi((char *)(ptr + 28)));
	ft_printf("Group ID:\t%d\n", ft_atoi((char *)(ptr + 34)));
	ft_printf("Mode:\t\t%d\n", ft_atoi((char *)(ptr + 40)));
	ft_printf("Size:\t\t%d\n", ft_atoi((char *)(ptr + 48)));
	ft_printf("End Header:\t  `\\n\n\n");
	ft_printf("Header line: \t%s\n\n\n", (char *)ptr);
}


void	ft_print_mach_header_64(struct mach_header_64	*mach_header)
{
	if (!mach_header)
		return ;
	ft_printf("Info NM ----- MACH_HEADER_64 ---------\n");
	ft_print_int16("Magic number: \t", (unsigned long long int)mach_header->magic, "\n");
	ft_printf("CpuType: \t%d (", mach_header->cputype);
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(mach_header->cputype, mach_header->cpusubtype)->name), ")", "\n");
	ft_print_int16("CpuSubType: \t", (uint16_t)mach_header->cpusubtype, "\n");
	ft_printf("File Type: \t%d\n", mach_header->filetype);
	ft_printf("Ncmds: \t\t%d\n", mach_header->ncmds);
	ft_printf("SizeofCmds: \t%d\n", mach_header->sizeofcmds);
	ft_print_int16("Flags: \t\t", mach_header->flags, "\n\n");
}

void	ft_print_fat_arch_64(struct fat_arch_64 *arch)
{
	if (!arch)
		return ;
	ft_printf("\nInfo NM --------------------- FAT_ARCH_64 ---------------------\n");
	ft_printf("CpuType: \t%d (", arch->cputype);
	// ft_print_str((char *)(NXGetArchInfoFromCpuType(arch->cputype, arch->cpusubtype)->name), ")", "\n");
	ft_printf("CpuSubType: \t%x\n", (uint16_t)arch->cpusubtype);
	ft_printf("Offset: \t%d\n", arch->offset);
	ft_printf("Size: \t\t%d\n", arch->size);
	ft_printf("Align: \t\t2^%d", arch->align);
	ft_printf(" (%d)\n", ft_power(2, arch->align));
	ft_printf("Reserved: \t%d\n\n", arch->reserved);
}

void	ft_print_fat_header(struct fat_header *header)
{
	if (!header)
		return ;
	ft_printf("Info NM ----- FAT_HEADER ---------\n");
	ft_print_int16("Magic number: \t", header->magic, "\n");
	ft_printf("Nb struct fat_arch: \t%d\n\n", header->nfat_arch);
}

void	ft_print_option_nm(void)
{
	ft_printf("Info NM -------- OPTION ---------\n");
	if (!(env()->opt))
	{
		ft_printf("Aucune option\n\n");
		return ;
	}
	ft_printf("-g:\t%s\n", (env()->opt & OPT_G) ? "Yes" : "No");
	ft_printf("-j:\t%s\n", (env()->opt & OPT_J) ? "Yes" : "No");
	ft_printf("-u:\t%s\n", (env()->opt & OPT_U) ? "Yes" : "No");
	ft_printf("-U:\t%s\n", (env()->opt & OPT_UU) ? "Yes" : "No");
	ft_printf("-r:\t%s\n", (env()->opt & OPT_R) ? "Yes" : "No");
	ft_printf("Variable opt = %d\n\n", env()->opt);
}

void	ft_print_env(void)
{
	t_env	*e;

	e = env();
	ft_printf("Info NM ----- ENV ---------\n");
	ft_printf("Cmd: \t\t%s\n", e->cmd);
	ft_printf("Print_name: \t%s\n", (e->print_name) ? "yes" : "non");
	ft_printf("File_name: \t%s\n", e->file_name);
	ft_printf("File_size: \t%d\n", e->file_size);
	ft_print_int16("File_ptr: \t", (unsigned long long int)e->ptr, "\n");
	if (ft_is_arc((char *)(e->ptr)))
		ft_print_str("Magic number: \t%s\n", "archive", "\n");
	else
		ft_print_int16("Magic number: \t", (unsigned long long int)(e->magic), "\n");
	ft_print_int16("Magic_mh number: \t", (unsigned long long int)(e->magic_mh), "\n");
	ft_printf("Swap: \t\t%d\n\n", e->swap);
}

void	ft_print_file(void)
{
	t_env	*e;

	e = env();
	ft_printf("Info NM --- PRINT FILE ------\n");
	print_memory(e->ptr, e->file_size);
	ft_printf("\n");
}
