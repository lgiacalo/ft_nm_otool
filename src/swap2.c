/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
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
