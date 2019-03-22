/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xuo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 02:57:53 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/23 20:56:16 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len_str(int ret, t_flags **flags)
{
	if ((*flags)->prec && ((*flags)->prec_val > ret))
	{
		(*flags)->prec_val = (*flags)->prec_val - ret;
		ret += (*flags)->prec_val;
	}
	else
		(*flags)->prec_val = 0;
	if ((*flags)->width && ((*flags)->width_val > ret))
	{
		(*flags)->width_val = (*flags)->width_val - ret;
		ret += (*flags)->width_val;
	}
	else
		(*flags)->width_val = 0;
	return (ret);
}

static int	ft_len(unsigned long long int *nbr, t_flags *flags,\
		char **base, int *len_nbr)
{
	*base = NULL;
	(flags->len & LEN_L) ? *nbr = (unsigned long)*nbr : 0;
	(flags->len & LEN_HH) ? *nbr = (unsigned char)*nbr : 0;
	(flags->len & LEN_H) ? *nbr = (unsigned short)*nbr : 0;
	(flags->len & LEN_LL) ? *nbr = (unsigned long long)*nbr : 0;
	(flags->len & LEN_J) ? *nbr = (uintmax_t)(*nbr) : 0;
	(flags->len == 0) ? *nbr = (unsigned int)*nbr : 0;
	*base = BASE_16;
	if ((flags)->prec && ((flags)->prec_val == 0) && *nbr == 0)
		return (0);
	*base = BASE_2;
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

int			ft_conv_b(unsigned long long int nbr, t_flags *flags, int fd)
{
	char	*base;
	char	*str;
	char	*str_nbr;
	int		len;
	int		len_nbr;

	if (!(ft_len(&nbr, flags, &base, &len_nbr)))
		return (ft_vide(flags, fd));
	len = ft_len_str(len_nbr, &flags);
	if (!(str = ft_strnew((size_t)len)))
		return (EXIT_FAILURE);
	ft_memset(str, ' ', len);
	len = (flags->att & ATT_MINUS) ?\
		(flags->prec_val) : (len - len_nbr);
	str_nbr = ft_pitoa_base(nbr, base);
	ft_strncpy((str + len), str_nbr, len_nbr);
	ft_memdel((void **)&str_nbr);
	(flags->prec) ? len -= flags->prec_val : 0;
	(flags->prec) ? ft_memset((str + len), '0', flags->prec_val) : 0;
	(flags->att & ATT_ZERO) ? ft_memset((str), '0', flags->width_val) : 0;
	len = ft_strlen(str);
	ft_putstr_fd(str, fd);
	ft_memdel((void **)&str);
	return (len);
}
