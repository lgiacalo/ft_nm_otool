/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/10 20:07:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int		ft_record_symtab_header(t_symtab_header *sym_h, void *ptr)
{
	if (!ft_verif_header_line((void *)((char *)ptr)))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR3));
	if (*(char *)ptr == '#')
		sym_h->name = (char *)(ptr + 60);
	else
		sym_h->name = (char *)ptr;
	sym_h->date = (char *)(ptr + 16);
	sym_h->userId = ft_atoi((char *)(ptr + 28));
	sym_h->groupId = ft_atoi((char *)(ptr + 34));
	sym_h->mode = ft_atoi((char *)(ptr + 40));
	sym_h->size = ft_atoi((char *)(ptr + 48));
	sym_h->next =	60 + ((*(char *)ptr == '#') ? ft_get_len_name_header_line(ptr) : 0);
	return (EXIT_SUCCESS);
}

int	ft_record_fat_arch_64(uint32_t magic, void *arch, struct fat_arch_64 *dst)
{
	struct fat_arch	ret;

	if (!(arch = ft_safe(arch, (ft_is_64(magic)) ?
					sizeof(struct fat_arch_64) : sizeof(struct fat_arch))))
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

int	ft_record_fat_header(void *header, struct fat_header *ret)
{
	if (!(header = (ft_safe(header, sizeof(struct fat_header)))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	else
	{
		*ret = *((struct fat_header *)(header));
		ret->nfat_arch = (ft_is_swap(ret->magic)) ?
			OSSwapInt32(ret->nfat_arch) : ret->nfat_arch;
	}
	return (EXIT_SUCCESS);
}
