/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:20:09 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/16 17:57:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return (NULL);
	current = *lst;
	while(current)
	{
		temp = current;
		current = current->next;
		del(temp->current);
		free(temp);
	}
	*lst = NULL;
}
