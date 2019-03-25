/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/10 20:07:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void    ft_print_lst_line()
{
	t_line   *line;
	int       i;

	line = env()->line;
	i = 1;
	ft_fdprintf(FDD, "***** PRINT LIST LINE *****\n");
	while (line)
	{
		ft_print_line(line, i);
		line = line->next;
		i++;
	}
}

t_line *ft_line_new(t_line new)
{
	t_line *ret;

	ret = NULL;
	if (!(ret = (t_line *)ft_memalloc(sizeof(t_line) * 1)))
		return (NULL);
	*ret = new;
	ret->next = NULL;
	return (ret);
}

t_line  *ft_line_search(t_line *new, int (*condition)(char *, char *))
{
	t_env *e;
	t_line *tmp;

	e = env();
	tmp = e->line;
	while (tmp)
	{
		if (condition && (*condition)(new->name, tmp->name) < 0)
			return ((e->line == tmp) ? NULL : tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void    ft_line_add(t_line *new, int (*condition)(char *, char *))
{
	t_env  *e;
	t_line *prev;

	prev = NULL;
	if (!new)
		return ;
	e = env();
	if (!(e->line))
		e->line = new;
	else
	{
		prev = ft_line_search(new, condition);
		if (!prev)
		{
			new->next = e->line;
			e->line = new;
		}
		else
		{
			if (prev->next)
				new->next = prev->next;
			prev->next = new;
		}
	}
}
