/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 20:55:51 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	ft_is_64(uint32_t magic)
{
	if (magic == FAT_MAGIC_64 || magic == MH_MAGIC_64
		|| magic == FAT_CIGAM_64 || magic == MH_CIGAM_64)
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}

int	ft_is_swap(uint32_t magic)
{
	if (magic == FAT_CIGAM || magic == MH_CIGAM
		|| magic == FAT_CIGAM_64 || magic == MH_CIGAM_64)
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}

int	ft_is_mh(uint32_t magic)
{
	if (magic == MH_MAGIC || magic == MH_CIGAM
		|| magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}

int	ft_is_fat(uint32_t magic)
{
	if (magic == FAT_MAGIC || magic == FAT_CIGAM
		|| magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}

int	ft_is_arc(char *arc)
{
	if (!ft_strncmp(arc, "!<arch>\n", 8))
		return (EXIT_SUCCES);
	return (EXIT_FAILUR);
}
