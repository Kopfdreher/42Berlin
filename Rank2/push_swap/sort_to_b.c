/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:10:03 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 11:16:35 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


static t_path	get_cheapest(t_list **a, t_list **b);
static t_path	path_finding_of(t_path path, t_list **a, t_list **b);
static int	nxt_smllst_to(int num, t_list *b);
//static int	find_rb(t_path path, t_list **b);
static t_path	cost_of(t_path path);
static t_path	set_path_type(t_path path, int type);
static int	max_of(int	x, int y);

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

static t_path	path_finding_of(t_path path, t_list **a, t_list **b)
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
/*
static int	find_rb(t_path path, t_list **b)
{
	t_list	*current;
	t_list	*next;

	if (!((*b)->next))
		return (0);
	current = *b;
	next = (*b)->next;
	while (path.rb < path.size_b)
	{
		if (*(int *)(current->content) > path.num 
			&& path.num > *(int *)(next->content))
			return (path.rb);
		current = next;
		if (!next->next)
			next = *b;
		else
			next = next->next;
		path.rb++;
	}
	return (path.rb);
}*/

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

static int	max_of(int	x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
