/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:22:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:29:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct section_64					*ft_swap_section_64(uint32_t magic, struct section_64 *sect)
{
	if (!ft_is_swap(magic))
		return (sect);
	sect->addr = OSSwapInt64(sect->addr);
	sect->size = OSSwapInt64(sect->size);
	sect->offset = OSSwapInt32(sect->offset);
	sect->align = OSSwapInt32(sect->align);
	sect->reloff = OSSwapInt32(sect->reloff);
	sect->nreloc = OSSwapInt32(sect->nreloc);
	sect->flags = OSSwapInt32(sect->flags);
	sect->reserved1 = OSSwapInt32(sect->reserved1);
	sect->reserved2 = OSSwapInt32(sect->reserved2);
	sect->reserved3 = OSSwapInt32(sect->reserved3);
	return (sect);
}

struct section						*ft_swap_section(uint32_t magic, struct section *sect)
{
	if (!ft_is_swap(magic))
		return (sect);
	sect->addr = OSSwapInt32(sect->addr);
	sect->size = OSSwapInt32(sect->size);
	sect->offset = OSSwapInt32(sect->offset);
	sect->align = OSSwapInt32(sect->align);
	sect->reloff = OSSwapInt32(sect->reloff);
	sect->nreloc = OSSwapInt32(sect->nreloc);
	sect->flags = OSSwapInt32(sect->flags);
	sect->reserved1 = OSSwapInt32(sect->reserved1);
	sect->reserved2 = OSSwapInt32(sect->reserved2);
	return (sect);
}

struct segment_command_64	*ft_swap_segment_command_64(uint32_t magic,
		struct segment_command_64 *seg)
{
	if (!ft_is_swap(magic))
		return (seg);
	seg->cmd = OSSwapInt32(seg->cmd);
	seg->cmdsize = OSSwapInt32(seg->cmdsize);
	seg->vmaddr = OSSwapInt64(seg->vmaddr);
	seg->vmsize = OSSwapInt64(seg->vmsize);
	seg->fileoff = OSSwapInt64(seg->fileoff);
	seg->filesize = OSSwapInt64(seg->filesize);
	seg->maxprot = OSSwapInt32(seg->maxprot);
	seg->initprot = OSSwapInt32(seg->initprot);
	seg->nsects = OSSwapInt32(seg->nsects);
	seg->flags = OSSwapInt32(seg->flags);
	return (seg);
}

struct segment_command	*ft_swap_segment_command(uint32_t magic,
		struct segment_command *seg)
{
	if (!ft_is_swap(magic))
		return (seg);
	seg->cmd = OSSwapInt32(seg->cmd);
	seg->cmdsize = OSSwapInt32(seg->cmdsize);
	seg->vmaddr = OSSwapInt32(seg->vmaddr);
	seg->vmsize = OSSwapInt32(seg->vmsize);
	seg->fileoff = OSSwapInt32(seg->fileoff);
	seg->filesize = OSSwapInt32(seg->filesize);
	seg->maxprot = OSSwapInt32(seg->maxprot);
	seg->initprot = OSSwapInt32(seg->initprot);
	seg->nsects = OSSwapInt32(seg->nsects);
	seg->flags = OSSwapInt32(seg->flags);
	return (seg);
}

struct mach_header_64	*ft_swap_mach_header_64(uint32_t magic,
		struct mach_header_64 *mach)
{
	if (!ft_is_swap(magic))
		return (mach);
	mach->magic = OSSwapInt32(mach->magic);
	mach->cputype = OSSwapInt32(mach->cputype);
	mach->cpusubtype = OSSwapInt32(mach->cpusubtype);
	mach->filetype = OSSwapInt32(mach->filetype);
	mach->ncmds = OSSwapInt32(mach->ncmds);
	mach->sizeofcmds = OSSwapInt32(mach->sizeofcmds);
	mach->flags = OSSwapInt32(mach->flags);
	mach->reserved = OSSwapInt32(mach->reserved);
	return (mach);
}

struct mach_header		*ft_swap_mach_header(uint32_t magic,
		struct mach_header *mach)
{
	if (!ft_is_swap(magic))
		return (mach);
	mach->magic = OSSwapInt32(mach->magic);
	mach->cputype = OSSwapInt32(mach->cputype);
	mach->cpusubtype = OSSwapInt32(mach->cpusubtype);
	mach->filetype = OSSwapInt32(mach->filetype);
	mach->ncmds = OSSwapInt32(mach->ncmds);
	mach->sizeofcmds = OSSwapInt32(mach->sizeofcmds);
	mach->flags = OSSwapInt32(mach->flags);
	return (mach);
}

struct fat_arch_64		*ft_swap_fat_arch_64(uint32_t magic,
		struct fat_arch_64 *arch)
{
	if (!ft_is_swap(magic))
		return (arch);
	arch->cputype = OSSwapInt32(arch->cputype);
	arch->cpusubtype = OSSwapInt32(arch->cpusubtype);
	arch->offset = OSSwapInt64(arch->offset);
	arch->size = OSSwapInt64(arch->size);
	arch->align = OSSwapInt32(arch->align);
	arch->reserved = OSSwapInt32(arch->reserved);
	return (arch);
}

struct fat_arch			*ft_swap_fat_arch(uint32_t magic,
		struct fat_arch *arch)
{
	if (!ft_is_swap(magic))
		return (arch);
	arch->cputype = OSSwapInt32(arch->cputype);
	arch->cpusubtype = OSSwapInt32(arch->cpusubtype);
	arch->offset = OSSwapInt32(arch->offset);
	arch->size = OSSwapInt32(arch->size);
	arch->align = OSSwapInt32(arch->align);
	return (arch);
}
