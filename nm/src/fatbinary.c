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

void ft_gestion_arch_fat(struct fat_arch_64 *arch)
{
	uint32_t magic;

	//creer variable magic_to_mach_header in env ! a remplir ici
	// et tester dans ft_mach_header_64

	if (!arch || !ft_is_safe(env()->ptr, arch->offset))
		return ; // + taille de la struct mach_header 64 ou pas !
	magic = *((uint32_t *)(env()->ptr + arch->offset));
	ft_print_fat_arch_64(arch);

	if (ft_is_mh(magic))
	 ft_mach_header_64((env()->ptr + arch->offset));
	else if (ft_is_arc((char *)(env()->ptr + arch->offset)))
		printf("its archive static !!\n");
	else
		printf("I dont know !!");
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

	i = -1;
	ft_record_fat_header(env()->ptr, &header);
	(!my_arch) ? ft_print_fat_header(&header) : 0;
	while (++i < header.nfat_arch)
	{
		ft_record_fat_arch_64(header.magic, env()->ptr + sizeof(struct fat_header)
			+ i * (ft_is_64(header.magic) ? sizeof(struct fat_arch_64)
			: sizeof(struct fat_arch)), &arch);
		if (!my_arch && MY_ARCHI == arch.cputype)
			return (ft_gestion_arch_fat(&arch));
		(my_arch) ? ft_gestion_arch_fat(&arch) : 0;
	}
	if (!my_arch)
		ft_fatbinary(1);
	return ;
}
