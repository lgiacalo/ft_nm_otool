/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:45:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct mach_header_64	ft_copy_mach_header_64(struct mach_header *src)
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

struct fat_arch_64	ft_copy_fat_arch_64(struct fat_arch *src)
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
