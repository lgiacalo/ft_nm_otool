/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 21:10:09 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 19:41:50 by lgiacalo         ###   ########.fr       */
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

# define EXIT_SUCCESS		1
# define EXIT_FAILURE		0

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
** Error
*/
void						ft_error_void(char *str);
int							ft_error_int(char *str);
void						*ft_error_star(char *str);

/*
** Function libft
*/
size_t						ft_strlen(const char *s);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_chrstr_ind(char c, char *str);

#endif
