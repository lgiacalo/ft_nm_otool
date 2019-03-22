/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:57:53 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/16 11:50:22 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_len_str(int ret, t_flags *flags, int *len)
{
	(!((flags)->prec && ((flags)->prec_val > ret))) ?\
		(flags)->prec_val = 0 : 0;
	if ((flags)->prec && ((flags)->prec_val > ret))
	{
		(flags)->prec_val = (flags)->prec_val - ret;
		ret += (flags)->prec_val;
	}
	ret += 2;
	if ((flags)->width && ((flags)->width_val > ret))
	{
		(flags)->width_val = (flags)->width_val - ret;
		ret += (flags)->width_val;
	}
	else
		(flags)->width_val = 0;
	*len = ret;
}

/*
**	(flags->len & LEN_UP_L) ? nbr = nbr : 0;
**	(flags->len & LEN_Z) ? nbr = nbr : 0;
*/

static int	ft_len(unsigned long long int *nbr, t_flags *flags)
{
	int	len_nbr;

	(flags->len & LEN_H) ? *nbr = (unsigned short)*nbr : 0;
	(flags->len & LEN_HH) ? *nbr = (unsigned char)*nbr : 0;
	(flags->len & LEN_L) ? *nbr = (unsigned long)*nbr : 0;
	(flags->len & LEN_LL) ? *nbr = (unsigned long long)*nbr : 0;
	(flags->len & LEN_J) ? *nbr = (uintmax_t)(*nbr) : 0;
	(flags->len == 0) ? *nbr = (unsigned int)*nbr : 0;
	len_nbr = (*nbr == 0 && ((flags->prec) && (flags->prec_val == 0)))\
			? 0 : ft_len_pnumbers_base(*nbr, BASE_16);
	return (len_nbr);
}

int			ft_conv_p(unsigned long long int nbr, t_flags *flags, int fd)
{
	char	*str;
	char	*str_nbr;
	int		len;
	int		len_nbr;

	ft_len_str((len_nbr = ft_len(&nbr, flags)), flags, &len);
	if (!(str = ft_strnew((size_t)len)))
		return (EXIT_FAILURE);
	ft_memset(str, ' ', len);
	len = (flags->att & ATT_MINUS) ? (2 + flags->prec_val) : (len - len_nbr);
	if (len_nbr != 0)
	{
		str_nbr = ft_pitoa_base(nbr, BASE_16);
		ft_strncpy((str + len), str_nbr, len_nbr);
		ft_memdel((void **)&str_nbr);
	}
	(flags->prec) ? (len -= flags->prec_val) : 0;
	(flags->prec) ? (ft_memset((str + len), '0', flags->prec_val)) : 0;
	(flags->att & ATT_ZERO) ? (len -= flags->width_val) : 0;
	(flags->att & ATT_ZERO) ? ft_memset((str + len), '0', flags->width_val) : 0;
	ft_strncpy((str + len - 2), "0x", 2);
	ft_putstr_fd(str, fd);
	len = ft_strlen(str);
	ft_memdel((void **)&str);
	return (len);
}
