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

int	ft_record_segment_cmd_64(uint32_t magic, void *ptr, struct segment_command_64 *dst)
{
	struct segment_command	ret;

	if (!(ptr = ft_safe(ptr, ((struct load_command *)ptr)->cmdsize)))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	*dst = *((struct segment_command_64 *)ptr);
	if (!ft_is_64(magic))
	{
		ret = *((struct segment_command *)dst);
		*dst = ft_copy_segment_cmd_64(&ret);
	}
	else
		ft_strncpy(dst->segname, ((struct segment_command_64 *)ptr)->segname, 16);
	return (EXIT_SUCCES);
}

int	ft_record_mach_header_64(uint32_t magic, void *ptr, struct mach_header_64 *dst)
{
	struct mach_header	ret;

	if (!(ptr = ft_safe(ptr, (ft_is_64(magic)) ?
					sizeof(struct mach_header_64) : sizeof(struct mach_header))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	*dst = *((struct mach_header_64 *)ptr);
	if (ft_is_64(magic))
		ft_swap_mach_header_64(magic, dst);
	else
	{
		ret = *((struct mach_header *)dst);
		*dst = ft_copy_mach_header_64(ft_swap_mach_header(magic, &ret));
	}
	return (EXIT_SUCCES);
}

int		ft_record_symtab_header(t_symtab_header *sym_h, void *ptr)
{
	if (!ft_verif_header_line((void *)((char *)ptr)))
		return (EXIT_FAILUR);
	if (*(char *)ptr == '#')
		sym_h->name = (char *)(ptr + 60);
	else	//TODO: a verifier pour les noms, a mon avis pas de '\0'
		sym_h->name = (char *)ptr;
//	env()->file_name_mh = sym_h->name;
	if (!ft_verif_base_nm((char *)ptr + 16, 10, 42) ||
		!ft_verif_base_nm((char *)ptr + 40, 8, 8)) //TODO: a verifier
		return (EXIT_FAILUR);
	sym_h->date = (char *)(ptr + 16);
	sym_h->userId = ft_atoi((char *)(ptr + 28));
	sym_h->groupId = ft_atoi((char *)(ptr + 34));
	sym_h->mode = ft_atoi((char *)(ptr + 40));
	sym_h->size = ft_atoi((char *)(ptr + 48));
	sym_h->next =	60 + ((*(char *)ptr == '#') ? ft_get_len_name_header_line(ptr) : 0);
	return (EXIT_SUCCES);
}

int	ft_record_fat_arch_64(uint32_t magic, void *arch, struct fat_arch_64 *dst)
{
	struct fat_arch	ret;

	if (!(arch = ft_safe(arch, (ft_is_64(magic)) ?
					sizeof(struct fat_arch_64) : sizeof(struct fat_arch))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	*dst = *((struct fat_arch_64 *)arch);
	if (ft_is_64(magic))
		ft_swap_fat_arch_64(magic, dst);
	else
	{
		ret = *((struct fat_arch *)dst);
		*dst = ft_copy_fat_arch_64(ft_swap_fat_arch(magic, &ret));
	}
	return (EXIT_SUCCES);
}

int	ft_record_fat_header(void *header, struct fat_header *ret)
{
	if (!(header = (ft_safe(header, sizeof(struct fat_header)))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	*ret = *((struct fat_header *)(header));
	ret->nfat_arch = (ft_is_swap(ret->magic)) ?
		OSSwapInt32(ret->nfat_arch) : ret->nfat_arch;
	return (EXIT_SUCCES);
}
