/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:43:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2019/02/01 19:44:04 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_print_int(char *str1, long long int nbr, char *str2)
{
	ft_fdprintf(FDD, "%s%lld%s", str1, nbr, str2);
}

void	ft_print_str(char *str1, char *str2, char *str3)
{
	ft_fdprintf(FDD, "%s%s%s", str1, str2, str3);
}
