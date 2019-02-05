/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:22:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 16:25:02 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint16_t	ft_swap16(uint32_t magic, uint16_t nb)
{
	return ((ft_swap(magic)) ? OSSwapInt16(nb) : nb);
}

uint32_t	ft_swap32(uint32_t magic, uint32_t nb)
{
	return ((ft_swap(magic)) ? OSSwapInt32(nb) : nb);
}

uint64_t	ft_swap64(uint32_t magic, uint64_t nb)
{
	return ((ft_swap(magic)) ? OSSwapInt64(nb) : nb);
}


