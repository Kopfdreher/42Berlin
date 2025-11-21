/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_fts.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:57:10 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/21 13:29:17 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list	*ft_lst2ndlast(t_list *lst)
{
	if (!lst && !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

static int	ft_reverse_rotate(t_list **stack)
{
	t_list	*new_last;
	t_list	*new_first;

	if (!(*stack) || !(*stack)->next)
	{
		ft_printf("NRR");
		return (0);
	}
	new_first = ft_lstlast(*stack);
	new_last = ft_lst2ndlast(*stack);
	new_first->next = *stack;
	new_last->next = NULL;
	*stack = new_first;
	return (1);
}

void	ft_rra(t_list **stack)
{
	if (ft_reverse_rotate(stack))
		ft_printf("rra");
	ft_printf("\n");
}

void	ft_rrb(t_list **stack)
{
	if (ft_reverse_rotate(stack))
		ft_printf("rrb");
	ft_printf("\n");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_reverse_rotate(stack_a))
		ft_printf("r");
	if (ft_reverse_rotate(stack_b))
		ft_printf("r");
	ft_printf("r\n");
}
