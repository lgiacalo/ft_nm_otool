/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:24:59 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 18:57:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void ft_free(void)
{
		t_line	*line;
		t_line	*tmp;

		line = env()->line;
		while (line)
		{
			tmp = line;
			if (line->name)
				free(line->name);
			line = line->next;
			free(tmp);
		}
}

t_env	*env(void)
{
	static t_env	e;

	return (&e);
}

void ft_reinit_sym(void)
{
	env()->symbol.t = 0;
	env()->symbol.d = 0;
	env()->symbol.b = 0;
}

void	ft_reinit_env(void)
{
	t_env	*e;

	e = env();
	e->file_name = NULL;
	e->file_name_mh = NULL; //TODO: a revoir !!
	e->file_size = 0;
	e->ptr = NULL;
	e->ptr_mh = NULL;
	e->magic = 0;
	e->magic_mh = 0;
	e->dec = 0;
	e->swap = 0; //TODO: Verificatoin utilisation ?
	e->line = NULL;
	e->symbol.t = 0;
	e->symbol.d = 0;
	e->symbol.b = 0;
	e->arch = 1;
}

t_env	*ft_init_env(void)
{
	t_env	*e;

	e = env();
	e->cmd = NM;
	e->opt = 0;
	e->print_name = 0;
	e->file_name = NULL;
	e->file_name_mh = NULL;
	e->file_size = 0;
	e->ptr = NULL;
	e->ptr_mh = NULL;
	e->magic = 0;
	e->magic_mh = 0;
	e->dec = 0;
	e->swap = 0;
	e->line = NULL;
	e->symbol.t = 0;
	e->symbol.d = 0;
	e->symbol.b = 0;
	e->arch = 1;
	return (e);
}
