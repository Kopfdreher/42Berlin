/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_path_finding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:01:33 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 18:03:00 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int		nxt_smllst_to(int num, t_list *b);
static t_path	cost_of(t_path path);
static t_path	set_path_type(t_path path, int type);
static int		max_of(int x, int y);

t_path	path_finding_of(t_path path, t_list **a, t_list **b)
{
	path.ra = 0;
	path.rra = 0;
	path.rb = 0;
	path.rrb = 0;
	path.ra = find_rotations(path.num, a);
	path.rra = path.size_a - path.ra;
	path.rb = find_rotations(nxt_smllst_to(path.num, *b), b);
	path.rrb = path.size_b - path.rb;
	return (cost_of(path));
}

static int	nxt_smllst_to(int num, t_list *b)
{
	int	nxt_smllst;
	int	current;
	int	biggest;

	nxt_smllst = INT_MIN;
	biggest = INT_MIN;
	while (b)
	{
		current = *(int *)(b->content);
		if (biggest < current)
			biggest = current;
		if (nxt_smllst < current && current < num)
			nxt_smllst = current;
		b = b->next;
	}
	if (nxt_smllst == INT_MIN)
		return (biggest);
	return (nxt_smllst);
}

/* type:  0 = up_up | 1 = dn_dn | 2 = up_dn | 3 = dn_up */
static t_path	cost_of(t_path path)
{
	int	cost[4];
	int	i;
	int	type;

	cost[0] = max_of(path.ra, path.rb);
	cost[1] = max_of(path.rra, path.rrb);
	cost[2] = path.ra + path.rrb;
	cost[3] = path.rb + path.rra;
	i = 0;
	path.cost = INT_MAX;
	while (i < 4)
	{
		if (cost[i] < path.cost)
		{
			type = i;
			path.cost = cost[i];
		}
		i++;
	}
	return (set_path_type(path, type));
}

/* type:  0 = up_up | 1 = dn_dn | 2 = up_dn | 3 = dn_up */
static t_path	set_path_type(t_path path, int type)
{
	if (type == 0 || type == 2)
		path.rra = 0;
	if (type == 1 || type == 3)
		path.ra = 0;
	if (type == 0 || type == 3)
		path.rrb = 0;
	if (type == 1 || type == 2)
		path.rb = 0;
	return (path);
}

static int	max_of(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
