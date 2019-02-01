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
# define OPT_G				(1 << 0)	//Display symbols extern (only majuscule)
# define OPT_J				(1 << 1)	//Display only name of symbol (name function)
# define OPT_U				(1 << 2)	//Display only symbols undefined (U, u)
# define OPT_UU				(1 << 3)	//Display all except symbols undefined
# define OPT_R				(1 << 4)	//Order inverse
# define OPT_NM				"gjuUr"

/*
**	OPTION NM
*/
# define OPT_H				(1 << 0)	//Display header (.a -> tous les headers)
										//	+ (verif pour les fats contenant ou non l'archi courante)


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
** Print
*/

void						ft_print_option_nm(void);

/*
** Error
*/

void						ft_error_void(char *str);
int							ft_error_int(char *str);
void						*ft_error_star(char *str);

int							ft_usage_nm(void);
int							ft_usage_otool(void);


/*
** Function libft
*/

int							ft_chrstr_ind(char c, char *str);

#endif
