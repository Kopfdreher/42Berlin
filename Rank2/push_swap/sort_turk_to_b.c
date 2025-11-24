/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:10:03 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 18:02:39 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_path	get_cheapest(t_list **a, t_list **b);

void	sort_to_b(t_list **a, t_list **b)
{
	t_path	*cheapest_path;

	cheapest_path = new_path();
	if (!cheapest_path)
		return ;
	ft_pb(a, b);
	while (*a)
	{
		*cheapest_path = get_cheapest(a, b);
		movement_table(cheapest_path, a, b);
		ft_pb(a, b);
	}
	free(cheapest_path);
}

static t_path	get_cheapest(t_list **a, t_list **b)
{
	t_list	*num_in_a;
	t_path	current_path;
	t_path	cheapest_path;

	current_path.size_a = ft_lstsize(*a);
	current_path.size_b = ft_lstsize(*b);
	cheapest_path.cost = INT_MAX;
	num_in_a = *a;
	while (num_in_a)
	{
		current_path.num = *(int *)(num_in_a->content);
		current_path = path_finding_of(current_path, a, b);
		if (cheapest_path.cost > current_path.cost)
			cheapest_path = current_path;
		num_in_a = num_in_a->next;
	}
	return (cheapest_path);
}
