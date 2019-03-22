/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:24:59 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/05 17:45:13 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_env	*env(void)
{
	static t_env	e;

	return (&e);
}

void	ft_reinit_env(void)
{
	t_env	*e;

	e = env();
	e->file_name = NULL;
	e->file_size = 0;
	e->ptr = NULL;
	e->magic = 0;
	e->swap = 0;
}

t_env	*ft_init_env(void)
{
	t_env	*e;

	e = env();
	e->cmd = NM;
	e->opt = 0;
	e->print_name = 0;
	e->file_name = NULL;
	e->file_size = 0;
	e->ptr = NULL;
	e->magic = 0;
	e->swap = 0;
	return (e);
}

void	ft_init_fat_arch_64(struct fat_arch_64 *arch)
{
	if (!arch)
		return ;
	arch->cputype = 0;
	arch->cpusubtype = 0;
	arch->offset = 0;
	arch->size = 0;
	arch->align = 0;
	arch->reserved = 0;
}

void	ft_init_fat_header(struct fat_header *header)
{
	if (!header)
		return ;
	header->magic = 0;
	header->nfat_arch = 0;
	return ;
}
