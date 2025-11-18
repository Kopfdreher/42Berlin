/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:15:18 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/18 15:40:18 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*changed_node;

	if (!lst || !f || !del)
		return (NULL);
	changed_node = NULL;
	new_list = NULL;
	while (lst)
	{
		changed_node = ft_lstnew(f(lst->content));
		if (!changed_node)
		{
			del(changed_node);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&new_list, changed_node);
		lst = lst->next;
	}
	return (new_list);
}
