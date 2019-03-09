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

int 	ft_record_fat_arch_64(uint32_t magic, void *arch, struct fat_arch_64 *dst)
{
	struct fat_arch 		ret;

	if (!(arch = ft_safe(arch, (ft_is_64(magic))
					? sizeof(struct fat_arch_64) : sizeof(struct fat_arch))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	else
	{
			*dst = *((struct fat_arch_64 *)arch);
			if (ft_is_64(magic))
				ft_swap_fat_arch_64(magic, dst);
			else
			{
				ret = *((struct fat_arch *)dst);
				*dst = ft_copy_fat_arch_64(ft_swap_fat_arch(magic, &ret));
			}
	}
	return (EXIT_SUCCESS);
}

int		ft_record_fat_header(void *header, struct fat_header *ret)
{
	if (!(header = (ft_safe(header, sizeof(struct fat_header)))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	else
	{
		*ret = *((struct fat_header *)(header));
		ret->nfat_arch = (ft_is_swap(ret->magic))
			? OSSwapInt32(ret->nfat_arch) : ret->nfat_arch;
	}
	return (EXIT_SUCCESS);
}
