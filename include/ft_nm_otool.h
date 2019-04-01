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

# define OPT_NM				"gjuaUr"
# define OPT_OTOOL		"tdma"

typedef struct				s_line
{
	uint64_t				addr;
	char					sym;
	char					*name;
	struct s_line			*next;
}							t_line;

typedef struct				s_sym
{
	int						t;
	int						d;
	int						b;
}							t_sym;

typedef struct				s_env
{
	char					*cmd;
	int						opt;
	uint8_t					print_name;
	char					*file_name;
	char					*file_name_mh;
	size_t					file_size;
	void					*ptr;
	void					*ptr_mh;
	uint32_t				magic;
	uint32_t				magic_mh;
	uint32_t				dec;
	uint8_t					arch;
	uint32_t				cputype;
	t_sym					symbol;
	t_line					*line;
	uint8_t					p_archive;

}							t_env;


void	          ft_load_command_otool(void *ptr, int ncmds);
void						ft_load_command_nm(void *ptr, int ncmds);

void						ft_mach_header_64(void	*ptr, uint32_t magic_mh);

t_env						*env(void);
t_env						*ft_init_env(void);
void						ft_reinit_env(void);
void 						ft_reinit_sym(void);


void						ft_loop_args(int argc, char **argv, int ind);

int							ft_record_load_command(uint32_t magic, void *ptr,
	struct load_command *dst);
int							ft_record_segment_cmd_64(uint32_t magic, void *ptr,
		struct segment_command_64 *dst, uint32_t cmdsize);

int							ft_is_safe(void *ptr, size_t size);
void						*ft_safe(void *ptr, size_t size);

void						ft_print_title(void);

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
void					print_memory(const void *addr, size_t size, uint64_t ad);

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
