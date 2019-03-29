/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 18:53:56 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

# include "libft.h"

/*
** TODO: suprimer include + 1 + fichier()
*/

# include <mach-o/arch.h>
# include <stdio.h>
# include <time.h>

# define BASE16_U		"0123456789ABCDEF"
# define BASE16_L		"0123456789abcdef"

# define EXIT_SUCCES	1
# define EXIT_FAILUR	0

# define ERROR1			" The file was not recognized as a valid object file"
# define ERROR2			": No such file or directory"
# define ERROR3			": truncated or malformed archive"
# define ERROR4			": truncated or malformed fat file"
# define ERROR5			" for arch x86_64 is not a Mach-O file or an file.a."
# define ERROR6			": truncated or malformed object"
# define ERR_MALLOC		"Malloc"

# define MY_ARCHI		CPU_TYPE_X86_64

typedef struct			s_1s2n
{
	char	*s1;
	int		n1;
	int		n2;
}						t_1s2n;

char					*ft_get_name_cpu(int cputype, int cpusubtype);

/*
** File
*/

int						ft_open_file(char *cmd, char *file, int *fd);
int						ft_close_file(char *cmd, char *file, int fd);
int						ft_check_file(int fd, char *file, char *cmd,
		size_t *size);
int						ft_mmap_file(int fd, size_t size, void **ptr);
int						ft_munmap_file(size_t size, void **ptr);

/*
**  Type file
*/

int						ft_is_swap(uint32_t magic);
int						ft_is_64(uint32_t magic);
int						ft_is_mh(uint32_t magic);
int						ft_is_fat(uint32_t magic);
int						ft_is_arc(char *arc);

/*
** Option
*/

int						ft_multi_args(int ind, int argc);
int						ft_parse_option(int argc, char **argv, char *list_opt,
		int *env_opt);

/*
** Prints
*/

void					ft_putnbr_long(long long int n);
void					ft_putnbr16(unsigned long long int n);
void					print_memory(const void *addr, size_t size);

void					ft_print_str(char *str1, char *str2, char *str3);
void					ft_print_int(char *str1, long long int nbr, char *str2);
void					ft_print_int16(char *str1, unsigned long long int nbr,
		char *str2);

/*
** Error
*/

void					ft_error_void(char *str);
void					ft_error_void3(char *str1, char *str2, char *str3);
int						ft_error_int(char *str);
int						ft_error_int3(char *str1, char *str2, char *str3);
void					*ft_error_star(char *str);

#endif
