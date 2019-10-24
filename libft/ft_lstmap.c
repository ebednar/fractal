/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:46:43 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/29 15:46:45 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lstclear(t_list *list)
{
	t_list *current;

	while (list)
	{
		current = list;
		list = list->next;
		free(current);
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*current;
	t_list	*prev;

	if (!lst)
		return (NULL);
	if (!(current = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
		return (NULL);
	list = current;
	prev = current;
	lst = lst->next;
	while (lst)
	{
		if (!(current = ft_lstnew((f(lst))->content, (f(lst))->content_size)))
		{
			lstclear(list);
			return (NULL);
		}
		prev->next = current;
		prev = prev->next;
		lst = lst->next;
	}
	return (list);
}
