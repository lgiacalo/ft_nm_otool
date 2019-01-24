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

int		ft_parse_option(int argc, char **argv)
{
	int	dec;

	dec = 1;
	if (argc < 2)
		return (dec);
	while (argv && argv[dec])
	{
		if (argv[dec][0] == '-')
		{
			if (argv[dec][1] == 'h')
				return (0);
			dec++;
		}
		else
			return (dec);
	}
	return ((dec > 1) ? dec : 0);
}

/*
** Commande NM
*/

int		main(int argc, char **argv)
{
	t_env 	*e;

	printf("Debut projet NM\n");
	e = ft_init_env();		
	if (!ft_parse_option(argc, argv))
		return (ft_error_int("Probleme option nm"));

//	ft_open_close(argc, argv);
	while(1);
	return (0);
}
