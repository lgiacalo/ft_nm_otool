/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:48:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct fat_arch_64	ft_record_fat_arch_64(uint32_t magic, void *arch)
{
	struct fat_arch_64	ret;
	struct fat_arch		*src;
	int					is_64;
	int					is_swap;

	ft_init_fat_arch_64(&ret);
	is_64 = ft_is_64(magic);
	is_swap = ft_swap(magic);
	if (!(arch = ft_safe(arch, (is_64)
					? sizeof(struct fat_arch_64) : sizeof(struct fat_arch))))
		ft_error_int3(env()->cmd, env()->file_name, ERROR3);
	else
	{
		ret = *((struct fat_arch_64 *)(arch));
		if (!is_64)
		{
			src = ((struct fat_arch *)arch);
			ret.cputype = ft_swap32(magic, src->cputype);
			ret.cpusubtype = ft_swap32(magic, src->cpusubtype);
			ret.offset = ft_swap32(magic, src->offset);
			ret.size = ft_swap32(magic, src->size);
			ret.align = ft_swap32(magic, src->align);
			ret.reserved = 0;
		}
	}
	return (ret);
}

struct fat_header	ft_record_fat_header(void *header)
{
	struct fat_header	ret;

	ft_init_fat_header(&ret);
	if (!(header = (ft_safe(header, sizeof(struct fat_header)))))
		ft_error_int3(env()->cmd, env()->file_name, ERROR3);
	else
	{
		ret = *((struct fat_header *)(header));
		ret.nfat_arch = (ft_swap(ret.magic))
			? OSSwapInt32(ret.nfat_arch) : ret.nfat_arch;
	}
	return (ret);
}
