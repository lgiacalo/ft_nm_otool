/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:03:47 by lgiacalo          #+#    #+#             */
/*   Updated: 2017/01/09 01:09:52 by lgiacalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	new = ft_lstnew(temp->content, temp->content_size);
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		temp = ft_lstnew(temp->content, temp->content_size);
		ft_lstadd_end(&new, temp);
		lst = lst->next;
	}
	return (new);
}
