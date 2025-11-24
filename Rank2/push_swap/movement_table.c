/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 18:24:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 14:32:41 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_rr(t_path *path, t_list **a, t_list **b);
void	move_ra(t_path *path, t_list **a, t_list **b);
void	move_rb(t_path *path, t_list **a, t_list **b);
void	move_rrr(t_path *path, t_list **a, t_list **b);
void	move_rra(t_path *path, t_list **a, t_list **b);
void	move_rrb(t_path *path, t_list **a, t_list **b);

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

void	move_rr(t_path *path, t_list **a, t_list **b)
{
	ft_rr(a, b);
	path->ra--;
	path->rb--;
}

void	move_ra(t_path *path, t_list **a, t_list **b)
{
	ft_ra(a);
	path->ra--;
}

void	move_rb(t_path *path, t_list **a, t_list **b)
{
	ft_rb(b);
	path->rb--;
}

void	move_rrr(t_path *path, t_list **a, t_list **b)
{
	ft_rrr(a, b);
	path->rra--;
	path->rrb--;
}

void	move_rra(t_path *path, t_list **a, t_list **b)
{
	ft_rra(a);
	path->rra--;
}

void	move_rrb(t_path *path, t_list **a, t_list **b)
{
	ft_rrb(b);
	path->rrb--;
}
