/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:33:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/03 17:36:44 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int		ft_error_int(char *str)
{
	ft_fdprintf(2, "Error : %s\n", str);
	return (EXIT_FAILUR);
}

int		ft_error_int3(char *str1, char *str2, char *str3)
{
	ft_fdprintf(2, "%s%s%s\n", str1, str2, str3);
	return (EXIT_FAILUR);
}

void	ft_error_void3(char *str1, char *str2, char *str3)
{
	ft_fdprintf(2, "%s%s%s\n", str1, str2, str3);
	return ;
}
