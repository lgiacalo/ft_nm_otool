/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:13:34 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:16:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_line	*ft_line_new(t_line new)
{
	t_line *ret;

	ret = NULL;
	if (!(ret = (t_line *)ft_memalloc(sizeof(t_line) * 1)))
		return (NULL);
	*ret = new;
	ret->next = NULL;
	return (ret);
}

t_line	*ft_search_addr(t_line *n, int (*condition)(uint64_t, uint64_t))
{
	t_line	*tmp;
	t_line	*prev;
	int		comp;

	tmp = env()->line;
	prev = tmp;
	while (tmp)
	{
		if (!ft_strcmp(n->name, tmp->name))
		{
			comp = (*condition)(n->addr, tmp->addr);
			if (condition && comp < 0)
				return ((env()->line == tmp) ? NULL : prev);
		}
		else
		{
			if (prev != tmp && !ft_strcmp(n->name, prev->name))
				return (prev);
		}
		if (!(tmp->next))
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

t_line	*ft_line_search(t_line *n, int (*condition)(const char *, const char *))
{
	t_env	*e;
	t_line	*tmp;
	t_line	*prev;
	int		comp;

	e = env();
	tmp = e->line;
	prev = tmp;
	while (tmp)
	{
		comp = (*condition)(n->name, tmp->name);
		if (!comp)
			return (ft_search_addr(n, ((e->opt & OPT_R) ? ft_tri_r : ft_tri)));
		if (condition && comp < 0)
			return ((e->line == tmp) ? NULL : prev);
		if (!(tmp->next))
			break ;
		prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_line_add(t_line *n, int (*condition)(const char *, const char *))
{
	t_env	*e;
	t_line	*prev;

	prev = NULL;
	if (!n)
		return ;
	e = env();
	if (!(e->line))
		e->line = n;
	else
	{
		prev = ft_line_search(n, condition);
		if (!prev)
		{
			n->next = e->line;
			e->line = n;
		}
		else
		{
			if (prev->next)
				n->next = prev->next;
			prev->next = n;
		}
	}
}
