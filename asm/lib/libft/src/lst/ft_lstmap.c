/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skapteli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:19:47 by skapteli          #+#    #+#             */
/*   Updated: 2017/03/06 17:16:21 by skapteli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *temp;

	head = NULL;
	if (lst)
	{
		if ((head = f(lst)) == NULL)
			return (NULL);
		temp = head;
		lst = lst->next;
		while (lst)
		{
			if ((temp->next = f(lst)) == NULL)
				return (NULL);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (head);
}
