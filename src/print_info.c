/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:47:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/04/03 20:45:22 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	*ft_print_archi(void)
{
	cpu_type_t	cputype;

	cputype = env()->cputype;
	if (cputype == CPU_TYPE_I386)
		return ("i386");
	if (cputype == CPU_TYPE_POWERPC)
		return ("ppc");
	if (cputype == CPU_TYPE_POWERPC64)
		return ("ppc64");
	if (cputype == CPU_TYPE_ARM)
		return ("arm");
	if (cputype == CPU_TYPE_ANY)
		return ("any");
	if (cputype == CPU_TYPE_I860)
		return ("i860");
	if (cputype == CPU_TYPE_HPPA)
		return ("hppa");
	if (cputype == CPU_TYPE_SPARC)
		return ("sparc");
	if (cputype == CPU_TYPE_ARM64)
		return ("arm64");
	if (cputype == CPU_TYPE_X86_64)
		return ("x86_64");
	return ("ooooo");
}

void	ft_print_title(void)
{
	t_env	*e;

	e = env();
	if (e->magic == 0)
	{
		ft_printf("\n%s(%s)", e->file_name, e->file_name_mh);
		(e->arch) ? ft_printf(":\n") : ft_printf(" (for architecture %s)\n",
			ft_print_archi());
	}
	else if (ft_is_fat(e->magic) && !(e->arch))
		ft_printf("\n%s (for architecture %s):\n", e->file_name,
			ft_print_archi());
	else if (e->print_name && !ft_is_fat(e->magic))
		ft_printf("\n%s:\n", e->file_name);
}

void	ft_print_title_otool(void)
{
	t_env	*e;

	e = env();
	if (e->magic == 0)
	{
		if (!(e->p_archive))
		{
			e->p_archive = 1;
			ft_printf("Archive : %s\n", e->file_name);
		}
		ft_printf("%s(%s)", e->file_name, e->file_name_mh);
		(e->arch) ? ft_printf(":\n") : ft_printf(" (architecture %s)\n",
			ft_print_archi());
	}
	else if (ft_is_fat(e->magic) && !(e->arch))
		ft_printf("%s (architecture %s):\n", e->file_name, ft_print_archi());
	else if (e->print_name)
		ft_printf("%s:\n", e->file_name);
}

void	ft_print_line(t_line *line)
{
	int	pad;
	int	opt;

	opt = env()->opt;
	pad = ft_is_64(env()->magic_mh) ? 16 : 8;
	if (!line || ((opt & OPT_G) && (int)line->sym != ft_toupper(line->sym))
	|| ((opt & OPT_U) && line->sym != 'U' && line->sym != 'u')
	|| ((opt & OPT_UU) && (line->sym == 'U' || line->sym == 'u')))
		return ;
	if (!(line->addr) && line->sym == 'U')
		(!(opt & OPT_J) && !(opt & OPT_U)) ? ft_printf("%*s ", pad, " ") : 0;
	else
		(!(opt & OPT_J) && !(opt & OPT_U)) ? ft_printf("%0*llx ", pad,
			line->addr) : 0;
	(!(opt & OPT_J) && !(opt & OPT_U)) ? ft_printf("%c ", line->sym) : 0;
	ft_printf("%s\n", line->name);
}

void	ft_print_lst_line(void)
{
	t_line	*line;

	line = env()->line;
	while (line)
	{
		ft_print_line(line);
		line = line->next;
	}
}
