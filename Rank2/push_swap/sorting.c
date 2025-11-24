/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:49:05 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 15:33:29 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	min_to_top(t_list **a);
void	sort_three(t_list **a);
int		find_min(t_list **a);

void dump_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	print_stacks(*a, *b);
	if (size == 2)
		ft_ra(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (ft_lstsize(*a) > 3)
		{
			print_stacks(*a, *b);
			min_to_top(a);
			print_stacks(*a, *b);
			ft_pb(a, b);
		}
		sort_three(a);
		while (*b)
			ft_pa(b, a);
	}
}

void	min_to_top(t_list **a)
{
	int	ra;
	int	rra;

	ra = find_rotations(find_min(a), a);
	rra = ft_lstsize(*a) - ra;
	if (ra < rra)
	{
		while (ra)
		{
			ft_ra(a);
			ra--;
		}
	}
	else
	{
		while (rra)
		{
			ft_rra(a);
			rra--;
		}
	}
}

int		find_min(t_list **a)
{
	t_list	*current;
	int		min_num;
	int 	current_num;

	min_num = INT_MAX;
	while (current)
	{
		current_num = *(int *)((*a)->content);
		if (min_num > current_num)
			min_num = current_num;
		current = current->next;
	}
	return (min_num);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)((*a)->content);
	second = *(int *)((*a)->next->content);
	third = *(int *)((*a)->next->next->content);
	if (first < second && second > third && third > first)
	{
		ft_rra(a);
		ft_sa(a);
	}
	if (first > second && second < third && third > first)
		ft_sa(a);
	if (first < second && second > third && third < first)
		ft_rra(a);
	if (first > second && second < third && third < first)
		ft_ra(a);
	if (first > second && second > third && third < first)
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	turk_sort(t_list **a, t_list **b)
{
	sort_to_b(a, b);
	back_to_a(a, b);
}
