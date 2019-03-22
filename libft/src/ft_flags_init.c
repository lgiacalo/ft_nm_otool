/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 08:17:37 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/20 17:31:20 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_flags_att(char **chaine, char conv)
{
	int	ret;
	int	ind;

	ret = 0;
	while ((ind = ft_chrstr_ind(**chaine, FLAGS_ATT)) >= 0)
	{
		(ret & (1 << ind)) ? 0 : (ret += (1 << ind));
		(*chaine)++;
	}
	((ret & ATT_MINUS) && (ret & ATT_ZERO)) ? ret ^= ATT_ZERO : 0;
	((ret & ATT_PLUS) && (ret & ATT_SPACE)) ? ret ^= ATT_SPACE : 0;
	if (conv == 'p')
		(ret & ATT_SHARP) ? 0 : (ret += ATT_SHARP);
	return (ret);
}

static int	ft_flags_width_suite(char **chaine, t_flags *flags, va_list ap)
{
	int	nbr;

	nbr = 0;
	(*chaine)++;
	flags->width = WIDTH_STAR;
	nbr = va_arg(ap, int);
	if (ft_atoi(*chaine) > 0)
	{
		nbr = ft_atoi(*chaine);
		flags->width = WIDTH;
		(*chaine) += ft_len_numbers(nbr);
	}
	else if (nbr < 0)
	{
		(flags->att & ATT_MINUS) ? 0 : (flags->att += ATT_MINUS);
		((flags->att & ATT_MINUS) && (flags->att & ATT_ZERO))\
			? flags->att ^= ATT_ZERO : 0;
		nbr *= -1;
	}
	return (nbr);
}

int			ft_flags_width(char **chaine, t_flags *flags, va_list ap)
{
	int	nbr;

	nbr = ft_atoi(*chaine);
	if (nbr > 0)
	{
		flags->width = WIDTH;
		(*chaine) += ft_len_numbers(nbr);
		if (**chaine == '*')
		{
			(*chaine)++;
			flags->width = WIDTH_STAR;
			nbr = va_arg(ap, int);
			if (nbr < 0)
			{
				(flags->att & ATT_MINUS) ? 0 : (flags->att += ATT_MINUS);
				((flags->att & ATT_MINUS) && (flags->att & ATT_ZERO))\
					? flags->att ^= ATT_ZERO : 0;
				nbr *= -1;
			}
		}
	}
	else if (**chaine == '*')
		nbr = ft_flags_width_suite(chaine, flags, ap);
	return (nbr);
}

int			ft_flags_prec(char **chaine, t_flags *flags)
{
	int	nbr;

	nbr = ft_strchr_ind(*chaine, '.');
	if (nbr < 0)
		return (0);
	(*chaine) += nbr + 1;
	nbr = ft_atoi(*chaine);
	flags->prec = PREC_POINT;
	if (nbr > 0)
		(*chaine) += ft_len_numbers(nbr);
	if (**chaine == '*')
	{
		(*chaine)++;
		flags->prec = PREC_STAR;
	}
	return (nbr);
}

int			ft_flags_len(char *chaine, char conv)
{
	if (conv == 'p')
		return (LEN_L);
	while (*chaine != '\0' && ft_chrstr_ind(*chaine, FLAGS_LEN) < 0)
		chaine++;
	if (*chaine == 'l')
		return ((*(chaine + 1) == 'l') ? LEN_LL : LEN_L);
	if (*chaine == 'h')
		return ((*(chaine + 1) == 'h') ? LEN_HH : LEN_H);
	if (*chaine == 'j')
		return (LEN_J);
	if (*chaine == 'L')
		return (LEN_UP_L);
	if (*chaine == 'z')
		return (LEN_Z);
	return (0);
}
