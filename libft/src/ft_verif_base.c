/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:58:16 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/05/10 21:47:59 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_verif_base(char *base)
{
	int	i;

	i = 0;
	if (!base || (ft_strlen(base) < 2))
		return (0);
	while (base[i] != '\0' && base[i + 1] != '\0')
	{
		if ((ft_chrstr_ind(base[i], (base + i + 1))) >= 0)
			return (0);
		i++;
	}
	if ((ft_strstrchr_ind("+-", base)) >= 0)
		return (0);
	return (1);
}
