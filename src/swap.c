/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:22:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:44:51 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct mach_header_64			*ft_swap_mach_header_64(uint32_t magic, struct mach_header_64 *mach)
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

struct mach_header			*ft_swap_mach_header(uint32_t magic, struct mach_header *mach)
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

struct fat_arch_64			*ft_swap_fat_arch_64(uint32_t magic, struct fat_arch_64 *arch)
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

struct fat_arch			*ft_swap_fat_arch(uint32_t magic, struct fat_arch *arch)
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

uint16_t	ft_swap16(uint32_t magic, uint16_t nb)
{
	return ((ft_is_swap(magic)) ? OSSwapInt16(nb) : nb);
}

uint32_t	ft_swap32(uint32_t magic, uint32_t nb)
{
	return ((ft_is_swap(magic)) ? OSSwapInt32(nb) : nb);
}

uint64_t	ft_swap64(uint32_t magic, uint64_t nb)
{
	return ((ft_is_swap(magic)) ? OSSwapInt64(nb) : nb);
}
