/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:35:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/03 17:18:35 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int		ft_mmap_file(int fd, size_t size, void **ptr)
{
	if (size <= 0 || !ptr)
		return (EXIT_FAILURE);
	*ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*ptr == MAP_FAILED)
		return (ft_error_int("mmap()"));
	return (EXIT_SUCCESS);
}

int		ft_munmap_file(size_t size, void **ptr)
{
	if (!ptr || !(*ptr) || size <= 0)
		return (EXIT_FAILURE);
	if (*ptr == MAP_FAILED || munmap(*ptr, size) == -1)
		return (ft_error_int("munmap()"));
	*ptr = NULL;
	return (EXIT_SUCCESS);
}

int		ft_open_file(char *cmd, char *file, int *fd)
{
	*fd = -1;
	if (!file)
		return (EXIT_FAILURE);
	*fd = open(file, O_RDONLY);
	if ((*fd) < 0)
		return (ft_error_int3(cmd, file, ERROR2));
	return (EXIT_SUCCESS);
}

int		ft_close_file(char *cmd, char *file, int fd)
{
	if (fd < 0)
		return (EXIT_FAILURE);
	if (close(fd) < 0)
		return (ft_error_int3(cmd, file, ": error to close file"));
	return (EXIT_SUCCESS);
}

int		ft_check_file(int fd, char *file, char *exec, size_t *size)
{
	struct stat	stat;

	if (fstat(fd, &stat) < 0)
		return (ft_error_int("function fstat"));
	*size = stat.st_size;
	if (!(S_ISREG(stat.st_mode)) && !(S_ISLNK(stat.st_mode)))
		return (ft_error_int3(exec, file, ERROR1));
	if (*size <= 0)
		return (ft_error_int3(exec, file, ERROR1));
	return (EXIT_SUCCESS);
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
			return (EXIT_FAILURE);
		while (argv[nb][i + 1])
		{
			if ((opt = ft_chrstr_ind(argv[nb][i + 1], list_opt)) < 0)
				return (EXIT_FAILURE);
			*(env_opt) |= (1 << opt);
			i++;
		}
		nb++;
	}
	return (nb);
}
