/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/04 18:38:48 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h> // a retirer - printf

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

# define BASE16_U		"0123456789ABCDEF"
# define BASE16_L		"0123456789abcdef"

# define EXIT_SUCCESS	1
# define EXIT_FAILURE	0

# define ERROR1			" The file was not recognized as a valid object file"
# define ERROR2			": No such file or directory"
# define ERROR3			": truncated or malformed archive"

/*
** File
*/
int						ft_open_file(char *cmd, char *file, int *fd);
int						ft_close_file(char *cmd, char *file, int fd);
int						ft_check_file(int fd, char *file, char *cmd, size_t *size);
int						ft_mmap_file(int fd, size_t size, void **ptr);
int						ft_munmap_file(size_t size, void **ptr);

/*
**  Type file
*/
int           ft_swap(uint32_t magic);
int           ft_is_64(uint32_t magic);
int           ft_is_mh(uint32_t magic);
int           ft_is_fat(uint32_t magic);
int           ft_is_arc(char *arc);

/*
** Option
*/
int						ft_multi_args(int ind, int argc);
int						ft_parse_option(int argc, char **argv, char *list_opt, int *env_opt);

/*
** Prints
*/
void					ft_putnbr(long long int n);
void					ft_putnbr16(unsigned long long int n);
void					print_memory(const void *addr, size_t size);

void					ft_putstr(const char *s);
void					ft_print_str(char *str1, char *str2, char *str3);
void					ft_print_int(char *str1, long long int nbr, char *str2);
void					ft_print_int16(char *str1, unsigned long long int nbr, char *str2);

/*
** Error
*/
void					ft_error_void(char *str);
void          ft_error_void3(char *str1, char *str2, char *str3);
int						ft_error_int(char *str);
int						ft_error_int3(char *str1, char *str2, char *str3);
void					*ft_error_star(char *str);

/*
** Function libft
*/
size_t					ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
int						ft_chrstr_ind(char c, char *str);

#endif
