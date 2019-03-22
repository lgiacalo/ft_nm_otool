/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 03:54:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/11 13:56:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "flags.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			conv;
	int			len;
	int			prec;
	int			prec_val;
	int			width;
	int			width_val;
	int			att;
	int			len_sharp;
}				t_flags;

void			ft_flags_init(t_flags *flags, char *chaine, va_list ap);

int				ft_flags_conv(char f_conv);
int				ft_flags_att(char **chaine, char conv);
int				ft_flags_width(char **chaine, t_flags *flags, va_list ap);
int				ft_flags_prec(char **chaine, t_flags *flags);
int				ft_flags_len(char *chaine, char conv);

int				ft_flags(va_list ap, t_flags *flags, int fd);

int				ft_conv_xuo(unsigned long long int nbr, t_flags *flags, int fd);
int				ft_conv_p(unsigned long long int nbr, t_flags *flags, int fd);
int				ft_conv_b(unsigned long long int nbr, t_flags *flags, int fd);
int				ft_conv_di(long long int nbr, t_flags *flags, int fd);
int				ft_conv_s(unsigned long int nbr, t_flags *flags, int fd);
int				ft_conv_c(int nbr, t_flags *flags, int fd);

#endif
