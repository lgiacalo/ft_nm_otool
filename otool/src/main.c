/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 22:33:00 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	ft_open_close(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 1;
	while (i < argc || i == 1)
	{
		if ((fd = open((argc == 1) ? "a.out" : argv[i], O_RDONLY)) < 0)
			ft_error_void((argc == 1) ? "a.out" : argv[i]);
		else
		{
			ft_check_file(fd, (argc == 1) ? "a.out" : argv[i], OTOOL, &(env()->file_size));
			if (close(fd) < 0)
				ft_error_void((argc == 1) ? "a.out" : argv[i]);
		}
		i++;
	}
	return ;
}

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env 	*e;

	printf("Debut projet OTOOL\n");
	e = ft_init_env();		
	if (!ft_parse_option(argc, argv, OPT_OTOOL, &(env()->opt)))
		return (ft_usage_otool());

	ft_print_option_otool();
//	ft_open_close(argc, argv);
	return (0);
}
