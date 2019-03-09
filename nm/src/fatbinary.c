/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatbinary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:45:36 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

/*
**	gestion de chaque types darch du fat
**    verifier si mh, or .a archive (fat d'archives)
*/

int ft_gestion_arch_fat(struct fat_arch_64 *arch)
{
	uint32_t magic;

	//creer variable magic_to_mach_header in env ! a remplir ici
	// et tester dans ft_mach_header_64

	//Ajoutez alignement pour verifier la taille !!! align que sur size ?
	if (!arch || !ft_is_safe(env()->ptr,
		ft_align(arch->offset + arch->size, ft_power(2, arch->align))))
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR4));
	magic = *((uint32_t *)(env()->ptr + arch->offset));
	ft_print_fat_arch_64(arch);

	if (ft_is_mh(magic))
	 ft_mach_header_64((env()->ptr + arch->offset), magic);
	else if (ft_is_arc((char *)(env()->ptr + arch->offset)))
		printf("its archive static !!\n");
	else  if (ft_is_fat(magic))
		printf("Its fat !!! encore ?? !!\n"); // normalement pas possible !
	else
	{
		//attention magic number inexistant
		printf("Piege probleme magic number !!\n");
		return (ft_error_int3(env()->cmd, env()->file_name, ERROR5));
		ft_print_mach_header_64((struct mach_header_64 *)(env()->ptr + arch->offset));
	}
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
	uint8_t							i;
	size_t							overlaps = 0;

	i = -1;
	ft_record_fat_header(env()->ptr, &header);
	(!my_arch) ? ft_print_fat_header(&header) : 0; //TODO: a retirer
	if (header.nfat_arch < 1)
		return (ft_error_void3(env()->cmd, env()->file_name, ERROR4));
	while (++i < header.nfat_arch)
	{
		if (!ft_record_fat_arch_64(header.magic, env()->ptr + sizeof(struct fat_header)
			+ i * (ft_is_64(header.magic) ? sizeof(struct fat_arch_64)
			: sizeof(struct fat_arch)), &arch) || (i && arch.offset < overlaps))
			return (ft_error_void3(env()->cmd, env()->file_name, ERROR4));
		if (!my_arch && MY_ARCHI == arch.cputype)
			return (ft_gestion_arch_fat(&arch));
		if (my_arch)
			if (ft_)
		(my_arch) ? ft_gestion_arch_fat(&arch) : 0;
		printf("Valeur overlaps = %zu || offset = %llu\n", overlaps, arch.offset);

		overlaps = ft_align(arch.offset + arch.size, ft_power(2, arch.align));
	}
	(!my_arch) ? ft_fatbinary(1) : 0;
	return ;
}
