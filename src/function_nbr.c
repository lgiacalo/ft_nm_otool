/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:43 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/03/25 19:03:10 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include "ft_otool.h"

static void	ft_print_ligne(unsigned char *str, size_t i, size_t size)
{
	size_t	k;

	k = i - 1;
	while (++k < (i + 16) && k < size)
	{
		ft_putchar(BASE16_L[(str[k] / 16)]);
		ft_putchar(BASE16_L[(str[k] % 16)]);
		(ft_is_ppc() && ((k + 1) % 4)) ? 0 : ft_putchar(' ');
	}
	k--;
	if (!(env()->opt & OPT_M))
		return;
	while (++k < (i + 16))
		ft_putstr("   ");
	k = i - 1;
	ft_putstr("\t");
	while (++k < (i + 16) && k < size)
		ft_putchar((str[k] >= 32 && str[k] < 127) ? str[k] : '.');
}

void		print_memory(const void *addr, size_t size, uint64_t ad)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)addr;
	while (i < size)
	{
		ft_printf("%0*llx\t", (ft_is_64(env()->magic_mh) ? 16 : 8), (ad + i));
		ft_print_ligne(str, i, size);
		ft_putchar('\n');
		i += 16;
	}
}
