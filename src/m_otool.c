/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_otool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:22:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		ft_text(void *ptr)
{
	ft_printf("Je suis text -->> OTOOL\n");
	struct section_64	sect;


	if (!ft_record_section_64(env()->magic_mh, ptr, &sect))
		return (EXIT_FAILUR);
	ft_print_section(&sect);
	if (!ft_is_safe(env()->ptr_mh + sect.offset, sect.size))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR6));
	return (EXIT_SUCCES);
}

int		ft_data(void *ptr)
{
	ft_printf("Je suis data -->> OTOOL\n");

	(void)ptr;
	return (EXIT_SUCCES);
}

int		ft_lc_segment_otool(void *ptr, struct load_command *lc)
{
	struct segment_command_64	seg;
	char						*str;
	int							k;
	int							st;

	k = -1;
	st = ft_is_64(env()->magic_mh);
	if (!ft_record_segment_cmd_64(env()->magic_mh, ptr, &seg, lc->cmdsize))
		return (EXIT_FAILUR);
	if (seg.nsects == 0)
		return (EXIT_SUCCES);
	while (((uint32_t)++k) < seg.nsects)
	{
		str = (char *)(((char *)ptr + (st ? sizeof(struct segment_command_64) :
		sizeof(struct segment_command))) + (k * (st ?
		sizeof(struct section_64) : sizeof(struct section))));
		if ((env()->opt & OPT_T) && !ft_strcmp("__text", str))
			return (ft_text((void *)str));
		else if ((env()->opt & OPT_D) && !ft_strcmp("__data", str))
			return (ft_data((void *)str));
	}
	return (EXIT_SUCCES);
}

void	ft_load_command_otool(void *ptr, int ncmds)
{
	ft_printf("Je suis dans load_command -->> OTOOL\n");
	struct load_command	lc;
	void	*tmp;
	int					i;
	int		ret;

	i = -1;
	tmp = ptr;
	ret = 1;
	while (++i < ncmds)
	{
		if (!ft_record_load_command(env()->magic_mh, tmp, &lc))
			return ;
		if (!ft_is_safe(tmp, lc.cmdsize))
			return (ft_error_void3(env()->cmd, env()->file_name, ERROR6));
		if (lc.cmd == LC_SEGMENT || lc.cmd == LC_SEGMENT_64)
			ret = ft_lc_segment_otool(tmp, &lc);
		if (!ret)
			return ;
		tmp = (struct load_command *)((char *)tmp + lc.cmdsize);
	}
	ft_print_title();
}
