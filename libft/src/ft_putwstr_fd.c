/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:41:18 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/02/15 06:33:05 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putwstr_fd(wchar_t *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putwchar_fd(*str, fd);
		str++;
	}
}
