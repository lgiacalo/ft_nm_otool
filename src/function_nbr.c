/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/11/06 21:27:22 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		ft_print_ligne(unsigned char *str, size_t i, size_t size)
{
	size_t	k;

	k = i - 1;
	while (++k < (i + 16) && k < size)
	{
		ft_putchar(BASE16_L[(str[k] / 16)]);
		ft_putchar(BASE16_L[(str[k] % 16)]);
		ft_putchar(' ');
	}
	k--;
	while (++k < (i + 16))
		ft_putstr("   ");
	k = i - 1;
	while (++k < (i + 16) && k < size)
		ft_putchar((str[k] >= 32 && str[k] < 127) ? str[k] : '.');
	ft_putchar('\n');
}

static void		print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)addr;
	while (i < size)
	{
		ft_print_int16("", (unsigned long long int)(str + i), " : ");
		ft_print_ligne(str, i, size);
		i += 16;
	}
}

void	ft_print_int16(char *str1, unsigned long long int nbr, char *str2)
{
	ft_putstr(str1);
	ft_putstr("0x");
	ft_putnbr16(nbr);
	ft_putstr(str2);
}

void	ft_putnbr(long long int n)
{
	long long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_putnbr16(unsigned long long int n)
{
	unsigned long long int	nbr;

	nbr = n;
	if (nbr < 16)
		ft_putchar(BASE16_U[nbr]);
	if (nbr >= 16)
	{
		ft_putnbr16((nbr / 16));
		ft_putnbr16((nbr % 16));
	}
}
