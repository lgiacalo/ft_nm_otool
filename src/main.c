/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:29:48 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/01/24 22:40:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_check_file(int fd)
{
	struct stat	buf;

	if (fstat(fd, &buf) < 0)
		ft_error_void("fstat");
	else
	{
		printf("Nbr fstat_size = %llu\n", buf.st_size);
		if ((buf.st_mode & S_IFMT) == S_IFREG)
			printf("fichier regulier\n");
	}
}

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
			ft_check_file(fd);
			if (close(fd) < 0)
				ft_error_void((argc == 1) ? "a.out" : argv[i]);
		}
		i++;
	}
	return ;
}

/*
**	Parsing Option
**		Erreur si : doublon, ou inconnu
**	A REFAIRE
*/

int		ft_parse_option(int argc, char **argv, char *list_opt)
{
	int opt;
	int	nb;
	int	i;

	if (argc == 1)
		return (1);
	nb = 1;
	while (nb < argc && argv[nb])
	{
		i = 0;
		if (argv[nb][i] != '-' || !ft_strcmp(argv[nb], "--"))
			return (1);
		else if (ft_strlen(argv[nb]) < 2)
			return (0);
		while (argv[nb][i + 1])
		{
			if ((opt = ft_chrstr_ind(argv[nb][i + 1], list_opt)) < 0)
				return (0);
			env()->opt |= (1 << opt);
			i++;
		}
		nb++;
	}
	return (1);
}

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env 	*e;

	printf("Debut projet NM\n");
	e = ft_init_env();		
	if (!ft_parse_option(argc, argv, OPT_NM))
		return (ft_usage_nm());

	if (env()->opt & OPT_U)
		env()->opt |= OPT_J;

//	ft_open_close(argc, argv);
	return (0);
}
