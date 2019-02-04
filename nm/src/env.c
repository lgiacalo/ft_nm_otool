/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:24:59 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 13:50:35 by lgiacalo         ###   ########.fr       */
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
}

t_env	*ft_init_env(void)
{
	t_env	*e;

	e = env();
	e->cmd = NM;
	e->opt = 0;
	e->file_name = NULL;
	e->file_size = 0;
	e->ptr = NULL;
	e->magic = 0;
	return (e);
}
