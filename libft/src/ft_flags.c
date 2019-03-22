/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:03:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/20 17:34:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_flags(va_list ap, t_flags *flags, int fd)
{
	int		len;

	if (flags->conv & CONV_PERC)
		len = ft_conv_c('%', flags, fd);
	if (flags->conv & (CONV_I | CONV_D | CONV_UP_D))
		len = ft_conv_di(va_arg(ap, long long int), flags, fd);
	if (flags->conv\
		& (CONV_X | CONV_UP_X | CONV_U | CONV_UP_U | CONV_O | CONV_UP_O))
		len = ft_conv_xuo(va_arg(ap, unsigned long long int), flags, fd);
	if (flags->conv & (CONV_P))
		len = ft_conv_p(va_arg(ap, unsigned long long int), flags, fd);
	if (flags->conv & (CONV_B))
		len = ft_conv_b(va_arg(ap, unsigned long long int), flags, fd);
	if (flags->conv & (CONV_C | CONV_UP_C))
		len = ft_conv_c(va_arg(ap, int), flags, fd);
	if (flags->conv & (CONV_S | CONV_UP_S))
		len = ft_conv_s(va_arg(ap, unsigned long int), flags, fd);
	return (len);
}

void	ft_flags_star(t_flags *flags, va_list ap)
{
	int	nbr2;

	nbr2 = 0;
	if (flags->prec & PREC_STAR)
	{
		nbr2 = va_arg(ap, int);
		if (nbr2 < 0)
			flags->prec_val = (flags->conv & CONV_S) ? (nbr2 * -1) : 0;
		else
			flags->prec_val = nbr2;
	}
}

void	ft_flags_init(t_flags *flags, char *chaine, va_list ap)
{
	char	conv;

	(void)ap;
	conv = chaine[ft_strlen(chaine) - 1];
	flags->att = ft_flags_att(&chaine, conv);
	if ((flags->att & ATT_SHARP) && ft_chrstr_ind(conv, "poOxXfF") < 0)
		flags->att ^= ATT_SHARP;
	if (ft_chrstr_ind(conv, "dDifF") < 0)
	{
		(flags->att & ATT_SPACE) ? flags->att ^= ATT_SPACE : 0;
		(flags->att & ATT_PLUS) ? flags->att ^= ATT_PLUS : 0;
	}
	flags->width = 0;
	flags->width_val = ft_flags_width(&chaine, flags, ap);
	flags->prec = 0;
	flags->prec_val = ft_flags_prec(&chaine, flags);
	if ((flags->att & ATT_ZERO) && (flags->prec & PREC_POINT)\
			&& (ft_chrstr_ind(conv, "dDioOuUxX") >= 0))
		flags->att ^= ATT_ZERO;
	flags->len = ft_flags_len(chaine, conv);
	ft_flags_star(flags, ap);
	flags->len_sharp = 0;
}
