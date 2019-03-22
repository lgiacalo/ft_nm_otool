/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:06:22 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/14 20:08:45 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*first;
	t_list	*second;

	first = *alst;
	if (!(*alst) || !((*alst)->next))
		return ;
	first = first->next;
	(*alst)->next = NULL;
	while (first)
	{
		second = first;
		first = first->next;
		second->next = *alst;
		*alst = second;
	}
}
