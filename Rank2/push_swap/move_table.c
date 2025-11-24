/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:24:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 17:59:04 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	movement_table(t_path *path, t_list **a, t_list **b)
{
	while (path->ra && path->rb)
		move_rr(path, a, b);
	while (path->ra)
		move_ra(path, a, b);
	while (path->rb)
		move_rb(path, a, b);
	while (path->rra && path->rrb)
		move_rrr(path, a, b);
	while (path->rra)
		move_rra(path, a, b);
	while (path->rrb)
		move_rrb(path, a, b);
}

t_path	*new_path(void)
{
	t_path	*new_path;

	new_path = malloc(sizeof(t_path));
	if (!new_path)
		return (NULL);
	new_path->num = 0;
	new_path->cost = 0;
	new_path->ra = 0;
	new_path->rb = 0;
	new_path->rra = 0;
	new_path->rrb = 0;
	new_path->size_a = 0;
	new_path->size_b = 0;
	return (new_path);
}

int	find_rotations(int num, t_list **a)
{
	t_list	*find_moves;
	int		rotations;

	find_moves = *a;
	rotations = 0;
	while (*(int *)(find_moves->content) != num)
	{
		rotations++;
		find_moves = find_moves->next;
	}
	return (rotations);
}
