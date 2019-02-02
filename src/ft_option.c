/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:35:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 22:29:17 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_check_file(int fd, char *file, char *exec, size_t *size)
{
	struct stat	stat;

	if (fstat(fd, &stat) < 0)
		return (ft_error_int("function fstat"));
	else
	{
		*size = stat.st_size;
		if (!(S_ISREG(stat.st_mode)) && !(S_ISLNK(stat.st_mode)))
			return (ft_error_int3(exec, file, ERROR1));
	}
	return (1);
}

int		ft_parse_option(int argc, char **argv, char *list_opt, int *env_opt)
{
	int opt;
	int	nb;
	int	i;

	nb = 1;
	if (argc == 1)
		return (nb);
	while (nb < argc && argv[nb])
	{
		i = 0;
		if (argv[nb][i] != '-' || !ft_strcmp(argv[nb], "--"))
			return ((argv[nb][i] != '-') ? nb : nb + 1);
		else if (ft_strlen(argv[nb]) < 2)
			return (0);
		while (argv[nb][i + 1])
		{
			if ((opt = ft_chrstr_ind(argv[nb][i + 1], list_opt)) < 0)
				return (0);
			*(env_opt) |= (1 << opt);
			i++;
		}
		nb++;
	}
	return (nb);
}
