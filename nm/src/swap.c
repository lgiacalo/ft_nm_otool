/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:22:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 13:41:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

size_t	ft_swap_fat_header(struct fat_header *header)
{
	if (!header)
		return (0);
	if (ft_swap(header->magic))
		return (OSSwapInt32(header->nfat_arch));
	return (header->nfat_arch);
}
