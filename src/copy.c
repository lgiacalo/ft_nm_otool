/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/04/03 20:32:07 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct section_64			ft_copy_section_64(struct section *src)
{
	struct section_64	dst;

	dst.addr = src->addr;
	dst.size = src->size;
	dst.offset = src->offset;
	dst.align = src->align;
	dst.reloff = src->reloff;
	dst.nreloc = src->nreloc;
	dst.flags = src->flags;
	dst.reserved1 = src->reserved1;
	dst.reserved2 = src->reserved2;
	dst.reserved3 = 0;
	return (dst);
}

struct segment_command_64	ft_copy_segment_cmd_64(struct segment_command *src)
{
	struct segment_command_64	dst;

	dst.cmd = src->cmd;
	dst.cmdsize = src->cmdsize;
	ft_strncpy(dst.segname, src->segname, 16);
	dst.vmaddr = src->vmaddr;
	dst.vmsize = src->vmsize;
	dst.fileoff = src->fileoff;
	dst.filesize = src->filesize;
	dst.maxprot = src->maxprot;
	dst.initprot = src->initprot;
	dst.nsects = src->nsects;
	dst.flags = src->flags;
	return (dst);
}

struct mach_header_64		ft_copy_mach_header_64(struct mach_header *src)
{
	struct mach_header_64	dst;

	dst.magic = src->magic;
	dst.cputype = src->cputype;
	dst.cpusubtype = src->cpusubtype;
	dst.filetype = src->filetype;
	dst.ncmds = src->ncmds;
	dst.sizeofcmds = src->sizeofcmds;
	dst.flags = src->flags;
	dst.reserved = 0;
	return (dst);
}

struct fat_arch_64			ft_copy_fat_arch_64(struct fat_arch *src)
{
	struct fat_arch_64	dst;

	dst.cputype = src->cputype;
	dst.cpusubtype = src->cpusubtype;
	dst.offset = src->offset;
	dst.size = src->size;
	dst.align = src->align;
	dst.reserved = 0;
	return (dst);
}
