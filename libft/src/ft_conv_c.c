/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:32:10 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/23 21:19:40 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_len_str(int nbr, t_flags *flags)
{
	int	ret;

	ret = nbr;
	if (flags->width && (flags->width_val > ret))
	{
		flags->width_val -= ret;
		ret += flags->width_val;
	}
	else
		flags->width_val = 0;
	return (ret);
}

static int	ft_conv_wchar(wchar_t str, t_flags *flags, int fd)
{
	char	*str_ret;
	int		ret;

	ret = ft_len_str(ft_wcharlen_o(str), flags);
	if (!(str_ret = ft_strnew((size_t)flags->width_val)))
		return (EXIT_FAILURE);
	ft_memset(str_ret, ' ', flags->width_val);
	if (flags->att & ATT_MINUS)
	{
		ft_putwchar_fd(str, fd);
		ft_putstr_fd(str_ret, fd);
	}
	else
	{
		(flags->att & ATT_ZERO) ? ft_memset(str_ret, '0', flags->width_val) : 0;
		ft_putstr_fd(str_ret, fd);
		ft_putwchar_fd(str, fd);
	}
	ft_memdel((void **)&str_ret);
	return (ret);
}

static int	ft_conv_char(char str, t_flags *flags, int fd)
{
	char	*str_ret;
	int		ret;

	ret = ft_len_str(1, flags);
	if (!(str_ret = ft_strnew((size_t)flags->width_val)))
		return (EXIT_FAILURE);
	ft_memset(str_ret, ' ', flags->width_val);
	if (flags->att & ATT_MINUS)
	{
		ft_putchar_fd(str, fd);
		ft_putstr_fd(str_ret, fd);
	}
	else
	{
		(flags->att & ATT_ZERO) ? ft_memset(str_ret, '0', flags->width_val) : 0;
		ft_putstr_fd(str_ret, fd);
		ft_putchar_fd(str, fd);
	}
	ft_memdel((void **)&str_ret);
	return (ret);
}

int			ft_conv_c(int nbr, t_flags *flags, int fd)
{
	int	ret;

	if ((flags->conv & CONV_UP_C)\
		|| ((flags->conv & CONV_C) && (flags->len & LEN_L)))
		ret = ft_conv_wchar((wchar_t)nbr, flags, fd);
	else
		ret = ft_conv_char((char)nbr, flags, fd);
	return (ret);
}
