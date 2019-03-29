/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:35:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:30:49 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print_lst_line(void)
{
	t_line	*line;
	int		i;

	line = env()->line;
	i = 1;
	while (line)
	{
		ft_print_line(line, i);
		line = line->next;
		i++;
	}
}

int		ft_tri_ascii(const char *s1, const char *s2)
{
	return (ft_strcmp(s1, s2));
}

int		ft_tri_ascii_r(const char *s1, const char *s2)
{
	return (-ft_strcmp(s1, s2));
}

int		ft_tri(uint64_t n1, uint64_t n2)
{
	return (n1 - n2);
}

int		ft_tri_r(uint64_t n1, uint64_t n2)
{
	return (-ft_tri(n1, n2));
}
