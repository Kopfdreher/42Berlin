/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:13:22 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 16:54:43 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_a_b_to_c(t_list **a, t_list **b, t_list **c)
{
	*a = *c;
	*b = *c;
}

char	**get_map_content(int map_fd)
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;
	char	*line;

	head = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		node = ft_lstnew(line);
		if (!node && !head)
			return (NULL);
		if (!node)
			return (ft_lstclear(&head, free), NULL);
		if (!head)
			set_a_b_to_c(&head, &tail, &node);
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	return (ft_lst_to_strarr(&head));
}
