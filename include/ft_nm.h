/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:19:15 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "ft_nm_otool.h"

/*
**	OPTION NM
*/

# define NM					"ft_nm: "

# define OPT_G				(1 << 0)
# define OPT_J				(1 << 1)
# define OPT_U				(1 << 2)
# define OPT_UU				(1 << 3)
# define OPT_R				(1 << 4)
# define OPT_NM				"gjuUr"

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
	uint8_t					swap;
	t_sym					symbol;
	t_line					*line;

}							t_env;

typedef struct				s_symtab_header
{
	char					*name;
	char					*date;
	int						userId;
	int						groupId;
	int						mode;
	int						size;
	int						next;
}							t_symtab_header;

/*
** Env
*/

t_env						*env(void);
t_env						*ft_init_env(void);
void						ft_reinit_env(void);

/*
**	Gestion fichier
*/

void						ft_fatbinary(int my_arch);
void						ft_archive_static(void *ptr, int max);
void						ft_mach_header_64(void	*ptr, uint32_t magic_mh);
void						ft_load_command(void *ptr, int ncmds);

int							ft_nlist(char *n_strx, uint8_t n_type,
		uint8_t n_sect, uint64_t n_value);

/*
**	Record structs
*/

int							ft_record_fat_header(void *header,
		struct fat_header *ret);
int							ft_record_fat_arch_64(uint32_t magic, void *arch,
		struct fat_arch_64 *dst);
int							ft_record_symtab_header(t_symtab_header *sym_h,
		void *ptr);
int							ft_record_mach_header_64(uint32_t magic, void *ptr,
		struct mach_header_64 *dst);
int							ft_record_segment_cmd_64(uint32_t magic, void *ptr,
		struct segment_command_64 *dst);

struct fat_arch_64			ft_copy_fat_arch_64(struct fat_arch *src);
struct mach_header_64		ft_copy_mach_header_64(struct mach_header *src);
struct segment_command_64	ft_copy_segment_cmd_64(struct segment_command *src);

/*
**	Fonction struct line
*/

t_line						*ft_line_new(t_line new);
t_line						*ft_line_search(t_line *n,
		int (*condition)(const char *, const char *));
void						ft_line_add(t_line *n,
		int (*condition)(const char *, const char *));

int							ft_tri_ascii(const char *s1, const char *s2);
int							ft_tri_ascii_r(const char *s1, const char *s2);
int							ft_tri(uint64_t n1, uint64_t n2);
int							ft_tri_r(uint64_t n1, uint64_t n2);

/*
**	Swap
*/

struct fat_arch_64			*ft_swap_fat_arch_64(uint32_t magic,
		struct fat_arch_64 *arch);
struct fat_arch				*ft_swap_fat_arch(uint32_t magic,
		struct fat_arch *arch);

struct mach_header_64		*ft_swap_mach_header_64(uint32_t magic,
		struct mach_header_64 *mach);
struct mach_header			*ft_swap_mach_header(uint32_t magic,
		struct mach_header *mach);

/*
**	Verif ptr in file
*/

int							ft_is_safe(void *ptr, size_t size);
void						*ft_safe(void *ptr, size_t size);
int							ft_verif_header_line(void *ptr);
int							ft_get_len_name_header_line(void *ptr);
size_t						ft_align(size_t nb, size_t modulo);
int							ft_verif_base_nm(char *str, int base, int len);
int							ft_strlen_nm(char *str);
char						*ft_strndup(char *s1, int len);

/*
** Print
*/

void						ft_print_option_nm(void);
void						ft_print_env(void);
void						ft_print_file(void);
void						ft_print_fat_header(struct fat_header *header);
void						ft_print_fat_arch_64(struct fat_arch_64 *arch);
void						ft_print_mach_header_64(struct mach_header_64
		*mach_header);
void						ft_print_symtab_header(t_symtab_header *sym_h);
void						ft_print_symtab_header2(void *ptr);
void						ft_print_load_command(struct load_command *lc,
		int numlc);
void						ft_print_segment_cmd_64(struct segment_command_64
		*seg);
void						ft_print_symtab_cmd(struct symtab_command *sym);
void						ft_print_lst_line();
void						ft_print_line(t_line *line, int i);

/*
** Usage
*/

int							ft_usage_nm(void);

#endif
