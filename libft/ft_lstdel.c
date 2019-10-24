/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:23:55 by ebednar           #+#    #+#             */
/*   Updated: 2018/11/29 15:23:56 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*previous;

	if (!alst || !del)
		return ;
	current = *alst;
	previous = current;
	while (current)
	{
		current = previous->next;
		ft_lstdelone(&previous, del);
		previous = current;
	}
	*alst = NULL;
}
