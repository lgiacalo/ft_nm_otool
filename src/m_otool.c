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

void	ft_load_command_otool(void *ptr, int ncmds)
{
	(void)ptr;
	(void)ncmds;
	ft_printf("Je suis dans load_command -->> OTOOL\n");
}
