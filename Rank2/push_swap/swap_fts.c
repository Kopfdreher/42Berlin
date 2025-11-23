/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:02:15 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/23 18:58:15 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	
	if (!(*stack) || !((*stack)->next))
	{
		// ft_printf("NS");
		return (0);
	}
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	ft_sa(t_list **stack)
{
	if (ft_swap(stack))
		ft_printf("sa");
	ft_printf(" ");
}

void	ft_sb(t_list **stack)
{
	if (ft_swap(stack))
		ft_printf("sb");
	ft_printf(" ");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_swap(stack_a))
		ft_printf("s");
	if (ft_swap(stack_b))
		ft_printf("s");
	ft_printf(" ");
}
