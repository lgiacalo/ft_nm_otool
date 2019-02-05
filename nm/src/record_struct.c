/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 14:17:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct fat_header	ft_record_fat_header(struct fat_header *header)
{
	struct fat_header	ret;

	ft_init_fat_header(&ret);
	if (!(header = (ft_safe(header, sizeof(struct fat_header)))))
		ft_error_int3(env()->cmd, env()->file_name, ERROR3);
	else
	{
		ret = *header;
		ret.nfat_arch = (ft_swap(ret.magic))
			? OSSwapInt32(ret.nfat_arch) : ret.nfat_arch;
	}
	return (ret);
}
