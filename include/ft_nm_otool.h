/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/12/15 19:31:11 by lgiacalo         ###   ########.fr       */
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

# define BASE16_U			"0123456789ABCDEF"
# define BASE16_L			"0123456789abcdef"

/*
**	OPTION NM
*/

# define OPT_G				(1 << 0)
# define OPT_H				(1 << 1)
# define OPT_J				(1 << 2)
# define OPT_U				(1 << 3)
# define OPT_M				(1 << 4)

# define EXIT_SUCCESS		1
# define EXIT_FAILURE		0

typedef struct				s_env
{
	int						opt;			//bits
	unsigned long long		fstat_size;
	void					*ptr;
	int						magic_number;
}							t_env;

/*
** Prints
*/

void						ft_putnbr(long long int n);
void						ft_putnbr16(unsigned long long int n);
void						print_memory(const void *addr, size_t size);

void						ft_putstr(const char *s);
void						ft_print_str(char *str1, char *str2, char *str3);
void						ft_print_int(char *str1, long long int nbr, char *str2);
void						ft_print_int16(char *str1, unsigned long long int nbr, char *str2);

/*
** Env
*/

t_env						*env(void);
t_env						*ft_init_env(void);


/*
** Error
*/

void						ft_error_void(char *str);
int							ft_error_int(char *str);
void						*ft_error_star(char *str);

#endif
