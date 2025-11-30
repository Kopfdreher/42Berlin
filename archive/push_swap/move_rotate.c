/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:48:41 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 19:45:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_rr(t_path *path, t_list **a, t_list **b)
{
	ft_rr(a, b);
	path->ra--;
	path->rb--;
}

void	move_ra(t_path *path, t_list **a)
{
	ft_ra(a);
	path->ra--;
}

void	move_rb(t_path *path, t_list **b)
{
	ft_rb(b);
	path->rb--;
}
