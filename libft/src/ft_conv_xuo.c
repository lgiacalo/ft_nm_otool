/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xuo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:57:53 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/16 11:50:32 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len_str(unsigned long long int nbr, int ret,\
		t_flags **flags)
{
	(!((*flags)->prec && ((*flags)->prec_val > ret))) ?\
		(*flags)->prec_val = 0 : 0;
	if ((*flags)->prec && ((*flags)->prec_val > ret))
	{
		(*flags)->prec_val = (*flags)->prec_val - ret;
		(((*flags)->conv & (CONV_O | CONV_UP_O)) &&\
			((*flags)->att & ATT_SHARP)) ? ((*flags)->prec_val)-- : 0;
		ret += (*flags)->prec_val;
	}
	(((*flags)->conv & (CONV_X | CONV_UP_X)) &&\
	((*flags)->att & ATT_SHARP) && (nbr != 0)) ? (*flags)->len_sharp = 2 : 0;
	(((*flags)->conv & (CONV_O | CONV_UP_O)) &&\
	((*flags)->att & ATT_SHARP) && (nbr != 0)) ? (*flags)->len_sharp = 1 : 0;
	((*flags)->len_sharp == 1) ? ret += 1 : 0;
	((*flags)->len_sharp == 2) ? ret += 2 : 0;
	(((*flags)->att & ATT_SHARP) && nbr == 0) ? (*flags)->len_sharp = 0 : 0;
	if ((*flags)->width && ((*flags)->width_val > ret))
	{
		(*flags)->width_val = (*flags)->width_val - ret;
		ret += (*flags)->width_val;
	}
	else
		(*flags)->width_val = 0;
	return (ret);
}

/*
**	(flags->len & LEN_UP_L) ? nbr = nbr : 0;
**	(flags->len & LEN_Z) ? nbr = nbr : 0;
*/

static int	ft_len(unsigned long long int *nbr, t_flags *flags,\
		char **base, int *len_nbr)
{
	*base = NULL;
	((flags->len & LEN_L) || (flags->conv & (CONV_UP_U | CONV_UP_O))) ?\
		*nbr = (unsigned long)*nbr : 0;
	(flags->len & LEN_HH && !(flags->conv & (CONV_UP_O | CONV_UP_U))) ?\
		*nbr = (unsigned char)*nbr : 0;
	(flags->len & LEN_H && !(flags->conv & (CONV_UP_O | CONV_UP_U))) ?\
		*nbr = (unsigned short)*nbr : 0;
	(flags->len & LEN_LL) ? *nbr = (unsigned long long)*nbr : 0;
	(flags->len & LEN_J) ? *nbr = (uintmax_t)(*nbr) : 0;
	(flags->len == 0 && !(flags->conv & (CONV_UP_U | CONV_UP_O))) ?\
		*nbr = (unsigned int)*nbr : 0;
	*base = BASE_16;
	if ((flags)->prec && ((flags)->prec_val == 0) && *nbr == 0\
	&& !((flags)->conv & (CONV_O | CONV_UP_O) && ((flags)->att & ATT_SHARP)))
		return (0);
	if (flags->conv & (CONV_UP_O | CONV_O))
		*base = BASE_8;
	if (flags->conv & (CONV_UP_U | CONV_U))
		*base = BASE_10;
	*len_nbr = ft_len_pnumbers_base(*nbr, *base);
	return (1);
}

static int	ft_vide(t_flags *flags, int fd)
{
	char	*str;

	if (flags->width && flags->width_val > 0)
	{
		if (!(str = ft_strnew((size_t)flags->width_val)))
			return (EXIT_FAILURE);
		ft_memset(str, ' ', flags->width_val);
		ft_putstr_fd(str, fd);
		ft_memdel((void **)&str);
	}
	return (flags->width_val);
}

static void	ft_conv_xuo_suite(char *str, int len, t_flags *flags, int fd)
{
	if (flags->prec)
	{
		len -= flags->prec_val;
		ft_memset((str + len), '0', flags->prec_val);
	}
	if (flags->att & ATT_ZERO)
	{
		len -= flags->width_val;
		ft_memset((str + len), '0', flags->width_val);
	}
	if ((flags->att & ATT_SHARP))
	{
		len -= flags->len_sharp;
		if (flags->conv & (CONV_X | CONV_UP_X))
			ft_strncpy((str + len), "0x", flags->len_sharp);
		else
		{
			ft_memset((str + len), '0', flags->len_sharp);
		}
	}
	if (flags->conv & CONV_UP_X)
		str = ft_strupcase(str);
	ft_putstr_fd(str, fd);
}

int			ft_conv_xuo(unsigned long long int nbr, t_flags *flags, int fd)
{
	char	*base;
	char	*str;
	char	*str_nbr;
	int		len;
	int		len_nbr;

	if (!(ft_len(&nbr, flags, &base, &len_nbr)))
		return (ft_vide(flags, fd));
	len = ft_len_str(nbr, len_nbr, &flags);
	if (!(str = ft_strnew((size_t)len)))
		return (EXIT_FAILURE);
	ft_memset(str, ' ', len);
	len = (flags->att & ATT_MINUS) ?\
		(flags->len_sharp + flags->prec_val) : (len - len_nbr);
	str_nbr = ft_pitoa_base(nbr, base);
	ft_strncpy((str + len), str_nbr, len_nbr);
	ft_memdel((void **)&str_nbr);
	ft_conv_xuo_suite(str, len, flags, fd);
	len = ft_strlen(str);
	ft_memdel((void **)&str);
	return (len);
}
