/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 06:52:51 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/16 11:50:19 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len_str(long long int nbr, int len_nbr, t_flags *flags)
{
	int	ret;

	ret = len_nbr;
	flags->att ^= (nbr < 0 && (flags->att & ATT_SPACE)) ? ATT_SPACE : 0;
	flags->att ^= (nbr < 0 && (flags->att & ATT_PLUS)) ? ATT_PLUS : 0;
	if ((flags->prec) && (flags->prec_val > ret))
	{
		flags->prec_val -= ret;
		ret += flags->prec_val;
	}
	else
		flags->prec_val = 0;
	(nbr < 0) ? ret++ : 0;
	(flags->att & ATT_SPACE) ? ret++ : 0;
	(flags->att & ATT_PLUS) ? ret++ : 0;
	if (flags->width && (flags->width_val > ret))
	{
		flags->width_val -= ret;
		ret += flags->width_val;
	}
	else
		flags->width_val = 0;
	flags->len_sharp = (nbr < 0 || (flags->att & (ATT_SPACE | ATT_PLUS))) ?\
						1 : 0;
	return (ret);
}

static int	ft_len_nbr(long long int *nbr, t_flags *flags)
{
	int	len_nbr;

	((flags->len & LEN_L) || (flags->conv & CONV_UP_D)) ?\
		*nbr = (long)*nbr : 0;
	(flags->len & LEN_HH && !(flags->conv & CONV_UP_D)) ? *nbr = (char)*nbr : 0;
	(flags->len & LEN_H && !(flags->conv & CONV_UP_D)) ? *nbr = (short)*nbr : 0;
	(flags->len & LEN_LL) ? *nbr = (long long)*nbr : 0;
	(flags->len & LEN_J) ? *nbr = (intmax_t)(*nbr) : 0;
	(flags->len & LEN_Z) ? *nbr = (size_t)*nbr : 0;
	(flags->len == 0 && !(flags->conv & CONV_UP_D)) ? *nbr = (int)*nbr : 0;
	len_nbr = ft_len_numbers_base(*nbr, BASE_10);
	len_nbr -= (*nbr < 0) ? 1 : 0;
	if (*nbr == 0 && flags->prec && (flags->prec_val == 0))
		len_nbr = 0;
	return (len_nbr);
}

/*
**	(flags->len & LEN_UP_L) ? nbr = nbr : 0;
*/

static void	ft_conv_di_suite(char *str, int ret[2], long long int nbr,\
		t_flags *flags)
{
	if (flags->prec)
	{
		ret[0] -= flags->prec_val;
		ft_memset((str + ret[0]), '0', flags->prec_val);
	}
	if (flags->att & ATT_ZERO)
	{
		ret[0] -= flags->width_val;
		ft_memset((str + ret[0]), '0', flags->width_val);
	}
	ret[0] -= flags->len_sharp;
	if (nbr < 0)
		*(str + ret[0]) = '-';
	if (flags->att & ATT_PLUS)
		*(str + ret[0]) = '+';
	ft_putstr_fd(str, ret[1]);
}

int			ft_conv_di(long long int nbr, t_flags *flags, int fd)
{
	char	*str_nbr;
	char	*str;
	int		ret[2];
	int		len_str;
	int		len_nbr;

	ret[1] = fd;
	len_nbr = ft_len_nbr(&nbr, flags);
	len_str = ft_len_str(nbr, len_nbr, flags);
	if (!(str = ft_strnew((size_t)len_str)))
		return (EXIT_FAILURE);
	ft_memset(str, ' ', len_str);
	if (flags->att & ATT_MINUS)
		ret[0] = flags->len_sharp + flags->prec_val;
	else
		ret[0] = len_str - len_nbr;
	str_nbr = ft_itoa_base(nbr, BASE_10);
	(nbr < 0) ? ft_strncpy((str + ret[0]), (str_nbr + 1), len_nbr)\
		: ft_strncpy((str + ret[0]), str_nbr, len_nbr);
	ft_memdel((void **)&str_nbr);
	ft_conv_di_suite(str, ret, nbr, flags);
	ft_memdel((void **)&str);
	return (len_str);
}
