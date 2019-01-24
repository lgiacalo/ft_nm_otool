/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:06:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/01/24 22:27:20 by lgiacalo         ###   ########.fr       */
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
