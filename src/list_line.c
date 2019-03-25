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

int		ft_tri_ascii(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2));
}

int		ft_tri_ascii_r(const char *s1, const char *s2)
{
	return (-ft_strcmp(s1, s2));
}

void    ft_print_lst_line()
{
	t_line   *line;
	int       i;

	line = env()->line;
	i = 1;
	ft_fdprintf(1, "\n***** PRINT LIST LINE *****\n");
	while (line)
	{
		ft_print_line(line, i);
		line = line->next;
		i++;
	}
	ft_fdprintf(1, "***** FIN PRINT LIST LINE *****\n\n");
}

t_line *ft_line_new(t_line new)
{
	t_line *ret;

	ret = NULL;
	if (!(ret = (t_line *)ft_memalloc(sizeof(t_line) * 1)))
		return (NULL);
	*ret = new;
	ret->next = NULL;
	ft_fdprintf(FDD, "\nVerification new line\n");
//	ft_print_line(ret, 0);
	ft_fdprintf(FDD, "FIN Verification new line\n");
	return (ret);
}

t_line  *ft_line_search(t_line *n, int (*condition)(const char *, const char *))
{
	t_env *e;
	t_line *tmp;
	t_line  *prev;
	int     comp;

	e = env();
	tmp = e->line;
	prev = tmp;
	while (tmp)
	{
		comp = (*condition)(n->name, tmp->name);
		ft_fdprintf(FDD, "Valeur cmp = %d - %s // %s\n", comp, n->name, tmp->name);
		// if cmp == 0 !! alors tri par rapport au addresse
		if (condition && comp < 0)
			return ((e->line == tmp) ? NULL : prev);
		if (!(tmp->next))
			break;
		prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

void    ft_line_add(t_line *n, int (*condition)(const char *, const char *))
{
	t_env  *e;
	t_line *prev;

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
