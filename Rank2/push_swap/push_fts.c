/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:01:57 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/23 18:59:25 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_new_first;
	t_list	*b_new_first;

	if (!(*stack_a))
	{
		//ft_printf("NP");
		return (0);
	}
	a_new_first = (*stack_a)->next;
	b_new_first = (*stack_a);
	b_new_first->next = *stack_b;
	*stack_a = a_new_first;
	*stack_b = b_new_first;
	return (1);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b))
		ft_printf("pb");
	ft_printf(" ");
}

void	ft_pa(t_list **stack_b, t_list **stack_a)
{
	if (ft_push(stack_b, stack_a))
		ft_printf("pa");
	ft_printf(" ");
}
