/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_struct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/04/03 20:46:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include "ft_otool.h"

int	ft_record_section_64(uint32_t magic, void *ptr, struct section_64 *dst)
{
	struct section	ret;

	if (!(ptr = ft_safe(ptr, (ft_is_64(magic)) ?
				sizeof(struct section_64) : sizeof(struct section))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	*dst = *((struct section_64 *)ptr);
	if (ft_is_64(magic))
		ft_swap_section_64(magic, dst);
	else
	{
		ret = *((struct section *)dst);
		*dst = ft_copy_section_64(ft_swap_section(magic, &ret));
	}
	ft_strncpy(dst->sectname, ((struct section_64 *)ptr)->sectname, 16);
	ft_strncpy(dst->segname, ((struct section_64 *)ptr)->segname, 16);
	return (EXIT_SUCCES);
}

int	ft_record_symtab_command(uint32_t magic, void *ptr,
		struct symtab_command *dst, uint32_t cmdsize)
{
	if (!(ptr = ft_safe(ptr, cmdsize)))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	*dst = *((struct symtab_command *)ptr);
	if (!ft_is_swap(magic))
		return (EXIT_SUCCES);
	dst->cmd = OSSwapInt32(dst->cmd);
	dst->cmdsize = OSSwapInt32(dst->cmdsize);
	dst->symoff = OSSwapInt32(dst->symoff);
	dst->nsyms = OSSwapInt32(dst->nsyms);
	dst->stroff = OSSwapInt32(dst->stroff);
	dst->strsize = OSSwapInt32(dst->strsize);
	return (EXIT_SUCCES);
}

int	ft_record_segment_cmd_64(uint32_t magic, void *ptr,
		struct segment_command_64 *dst, uint32_t cmdsize)
{
	struct segment_command	ret;

	if (!(ptr = ft_safe(ptr, cmdsize)))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	*dst = *((struct segment_command_64 *)ptr);
	if (!ft_is_64(magic))
	{
		ret = *((struct segment_command *)dst);
		*dst = ft_copy_segment_cmd_64(ft_swap_segment_command(magic, &ret));
	}
	else
	{
		ft_swap_segment_command_64(magic, dst);
		ft_strncpy(dst->segname, ((struct segment_command_64 *)ptr)->segname,
			16);
	}
	return (EXIT_SUCCES);
}
