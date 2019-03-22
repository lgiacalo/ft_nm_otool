/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:02:36 by lgiacalo          #+#    #+#             */
/*   Updated: 2016/11/13 05:02:38 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!(*alst))
		return ;
	temp = *alst;
	while (temp)
	{
		*alst = temp;
		temp = (temp)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	*alst = NULL;
}
