/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:49:14 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 17:50:36 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
