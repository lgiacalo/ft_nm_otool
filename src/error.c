/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 22:33:45 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/02 22:34:08 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_error_void(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return ;
}

int		ft_error_int(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (EXIT_FAILURE);
}

void	*ft_error_star(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (NULL);
}

int		ft_error_int3(char *str1, char *str2, char *str3)
{
	ft_print_str(str1, str2, str3);
	ft_putstr("\n");
	return (EXIT_FAILURE);
}
