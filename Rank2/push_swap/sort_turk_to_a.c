/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:16:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 17:41:33 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int		max_in(t_list *stack);
static t_path	to_a(t_path path);

void	back_to_a(t_list **a, t_list **b)
{
	t_path	*path;

	path = new_path();
	if (!path)
		return ;
	path->size_b = ft_lstsize(*b);
	path->rb = find_rotations(max_in(*b), b);
	*path = to_a(*path);
	movement_table(path, a, b);
	while (*b)
		ft_pa(b, a);
	free(path);
}

static int	max_in(t_list *stack)
{
	int	max;
	int	current;

	max = INT_MIN;
	while (stack)
	{
		current = *(int *)(stack->content);
		if (max < current)
			max = current;
		stack = stack->next;
	}
	return (max);
}

static t_path	to_a(t_path path)
{
	path.rrb = path.size_b - path.rb;
	if (path.rrb > path.rb)
		path.rrb = 0;
	else if (path.rrb < path.rb)
		path.rb = 0;
	else
		path.rrb = 0;
	return (path);
}
