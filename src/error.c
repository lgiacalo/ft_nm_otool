/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:06:27 by lgiacalo          #+#    #+#             */
/*   Updated: 2018/12/15 20:24:57 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	error_void(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return ;
}

int		error_int(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (EXIT_FAILURE);
}

void	*error_star(char *str)
{
	ft_print_str("Error : ", str, "\n");
	return (NULL);
}
