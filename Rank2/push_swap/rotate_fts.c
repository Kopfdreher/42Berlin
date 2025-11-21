/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:39:18 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/21 13:53:57 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static	int	ft_rotate(t_list **stack)
{
	t_list	*new_end;
	t_list	*new_first;

	if (!(*stack))
	{
		ft_printf("NR");
		return (0);
	}
	new_end = *stack;
	new_first = (*stack)->next;
	*stack = new_first;
	ft_lstadd_back(&new_first, new_end);
	new_end->next = NULL;
	return (1);
}

void	ft_ra(t_list **stack)
{
	if (ft_rotate(stack))
		ft_printf("ra");
	ft_printf("\n");
}

void	ft_rb(t_list **stack)
{
	if (ft_rotate(stack))
		ft_printf("rb");
	ft_printf("\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a))
		ft_printf("r");
	if (ft_rotate(stack_b))
		ft_printf("r");
	ft_printf("\n");
}
