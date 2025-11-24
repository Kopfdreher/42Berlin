/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 20:13:56 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 14:47:02 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	nums_have_dups(t_list **a)
{
	t_list	*current;
	t_list	*compare;
	int		current_num;
	int		compare_num;

	current = *a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			current_num = *(int *)(current->content);
			compare_num = *(int *)(compare->content);
			if (current_num == compare_num)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

long	num_too_big(long num)
{
	return (num < INT_MIN || num > INT_MAX);
}

int	nums_sorted(t_list **a)
{
	t_list	*current;
	int		current_num;
	int		next_num;

	current = *a;
	while (current->next)
	{
		current_num = *(int *)(current->content);
		next_num = *(int *)(current->next->content);
		if (current_num > next_num)
			return (0);
		current = current->next;
	}
	return (1);
}

