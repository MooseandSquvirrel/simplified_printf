/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 14:55:44 by agardner          #+#    #+#             */
/*   Updated: 2018/05/17 00:06:08 by agardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *newnode;
	t_list *previousnode;

	newlst = NULL;
	if (lst)
	{
		newlst = (*f)(lst);
		previousnode = newlst;
		lst = lst->next;
		while (lst)
		{
			newnode = (*f)(lst);
			previousnode->next = newnode;
			previousnode = newnode;
			lst = lst->next;
		}
		previousnode->next = NULL;
	}
	return (newlst);
}
