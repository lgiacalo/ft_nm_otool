/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 05:23:35 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/07/12 14:58:21 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# define COLOR(s,n,fd) ft_putstr_fd_nb(s, fd), (*i += n - 1)

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[00m"

# define BASE_2			"01"
# define BASE_8			"01234567"
# define BASE_10		"0123456789"
# define BASE_16		"0123456789abcdef"
# define FLAGS_CONV		"sSpdDioOuUxXcCb%"
# define FLAGS_LEN		"hlLjz"
# define FLAGS_ATT		"#0- +"

# define CONV_S			(1 << 0)
# define CONV_UP_S		(1 << 1)
# define CONV_P			(1 << 2)
# define CONV_D			(1 << 3)
# define CONV_UP_D		(1 << 4)
# define CONV_I			(1 << 5)
# define CONV_O			(1 << 6)
# define CONV_UP_O		(1 << 7)
# define CONV_U			(1 << 8)
# define CONV_UP_U		(1 << 9)
# define CONV_X			(1 << 10)
# define CONV_UP_X		(1 << 11)
# define CONV_C			(1 << 12)
# define CONV_UP_C		(1 << 13)
# define CONV_PERC		(1 << 14)
# define CONV_E			(1 << 15)
# define CONV_UP_E		(1 << 16)
# define CONV_F			(1 << 17)
# define CONV_UP_F		(1 << 18)
# define CONV_G			(1 << 19)
# define CONV_UP_G		(1 << 20)
# define CONV_A			(1 << 21)
# define CONV_UP_A		(1 << 22)
# define CONV_N			(1 << 23)
# define CONV_B			(1 << 24)
# define CONV_R			(1 << 25)

# define ATT_SHARP		(1 << 0)
# define ATT_ZERO		(1 << 1)
# define ATT_MINUS		(1 << 2)
# define ATT_SPACE		(1 << 3)
# define ATT_PLUS		(1 << 4)

# define WIDTH			(1 << 0)
# define WIDTH_STAR		(1 << 1)
# define WIDTH_STAR_M	(1 << 2)

# define PREC_POINT		(1 << 0)
# define PREC_STAR		(1 << 1)
# define PREC_STAR_M	(1 << 2)

# define LEN_HH			(1 << 0)
# define LEN_H			(1 << 1)
# define LEN_L			(1 << 2)
# define LEN_LL			(1 << 3)
# define LEN_UP_L		(1 << 4)
# define LEN_J			(1 << 5)
# define LEN_Z			(1 << 6)

#endif
