/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:36:17 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/03 17:36:42 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

/*
**	TODO: ajouter error here !!
*/

int		ft_mmap_file(int fd, size_t size, void **ptr)
{
	if (size <= 0 || !ptr)
		return (EXIT_FAILUR);
	*ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*ptr == MAP_FAILED)
		return (ft_error_int("mmap()"));
	return (EXIT_SUCCES);
}

int		ft_munmap_file(size_t size, void **ptr)
{
	if (!ptr || !(*ptr) || size <= 0)
		return (EXIT_FAILUR);
	if (*ptr == MAP_FAILED || munmap(*ptr, size) == -1)
		return (ft_error_int("munmap()"));
	*ptr = NULL;
	return (EXIT_SUCCES);
}

int		ft_open_file(char *cmd, char *file, int *fd)
{
	*fd = -1;
	if (!file)
		return (EXIT_FAILUR);
	*fd = open(file, O_RDONLY);
	if ((*fd) < 0)
		return (ft_error_int3(cmd, file, ERROR2));
	return (EXIT_SUCCES);
}

int		ft_close_file(char *cmd, char *file, int fd)
{
	if (fd < 0)
		return (EXIT_FAILUR);
	if (close(fd) < 0)
		return (ft_error_int3(cmd, file, ": error to close file"));
	return (EXIT_SUCCES);
}

int		ft_check_file(int fd, char *file, char *cmd, size_t *size)
{
	struct stat	stat;

	if (fstat(fd, &stat) < 0)
		return (ft_error_int("function fstat"));
	*size = stat.st_size;
	if (!(S_ISREG(stat.st_mode)) && !(S_ISLNK(stat.st_mode)))
		return (ft_error_int3(cmd, file, ERROR1));
	if (*size <= 0)
		return (ft_error_int3(cmd, file, ERROR1));
	return (EXIT_SUCCES);
}
