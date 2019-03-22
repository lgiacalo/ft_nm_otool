/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 01:11:49 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/09 01:11:50 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstat(t_list *lst, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && lst)
	{
		lst = lst->next;
		i++;
	}
	if (i == nbr && lst)
		return (lst);
	return (NULL);
}
