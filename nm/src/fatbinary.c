/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatbinary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/10 20:05:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**	gestion de chaque types darch du fat
**    verifier si mh, or .a archive (fat d'archives)
*/

int		ft_gestion_arch_fat(struct fat_arch_64 *arch)
{
	uint32_t magic;
	//TODO:align
	//Ajoutez alignement pour verifier la taille !!! align que sur size ?
	//Probleme alignement memoire avec resources/tests/archTest/998_valid_x86-64_i386.out
	if (!arch || !ft_is_safe(env()->ptr,
		arch->offset + arch->size))
		// ft_align(arch->offset + arch->size, ft_power(2, arch->align))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	magic = *((uint32_t *)(env()->ptr + arch->offset));
	ft_print_fat_arch_64(arch);
	if (ft_is_mh(magic))
		ft_mach_header_64((env()->ptr + arch->offset), magic);
	else if (ft_is_arc((char *)(env()->ptr + arch->offset)))
		ft_archive_static(env()->ptr + arch->offset, arch->size);
	else  if (ft_is_fat(magic))
	{
		// ft_print_fat_header((struct fat_header *)(env()->ptr + arch->offset));
		ft_print_int16("Its fat !!! encore ?? Magic number: \t", (unsigned long long int)magic, "\n");
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR3));
	}
	else
	{
		ft_print_int16("Piege probleme magic number ? Magic number: \t", (unsigned long long int)magic, "\n");
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR5));
	}
	return (EXIT_SUCCESS);
}

/*
**	Gestion fat binary2
**		Verif overlaps offset
**			+ call ft_gestion_arch_fat()
*/

int		ft_fatbinary2(int ind, size_t *overlaps, struct fat_arch_64 *arch, int my_arch)
{
	if (ind && arch->offset < *overlaps)
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	*overlaps = ft_align(arch->offset + arch->size, ft_power(2, arch->align));
	if (!my_arch && MY_ARCHI == arch->cputype)
	{
		ft_gestion_arch_fat(arch);
		return (EXIT_FAILURE);
	}
	if (my_arch && !ft_gestion_arch_fat(arch))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
**	Gestion fat binary
**		Lecture Fat_header
**			+ boucle sur n (fat_header.nfat_arch) fat_arch(64 ?)
*/

void	ft_fatbinary(int my_arch)
{
	struct fat_header	header;
	struct fat_arch_64	arch;
	uint8_t				i;
	size_t				overlaps;

	i = -1;
	ft_record_fat_header(env()->ptr, &header);
	(!my_arch) ? ft_print_fat_header(&header) : 0; //TODO: a retirer
	if (header.nfat_arch < 1)
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR4));
	while (++i < header.nfat_arch)
	{
		if (!ft_record_fat_arch_64(header.magic, env()->ptr +
		sizeof(struct fat_header) + i * (ft_is_64(header.magic) ?
		sizeof(struct fat_arch_64) : sizeof(struct fat_arch)), &arch) ||
		!ft_fatbinary2(i, &overlaps, &arch, my_arch))
			return ;
	}
	(!my_arch) ? ft_fatbinary(1) : 0;
	return ;
}
