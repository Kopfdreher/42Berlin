/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:11:49 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/22 22:33:57 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_error();
void	args_to_stack(char *argv[], t_list **stack);
void	print_stacks(t_list *a, t_list *b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 3 || input_has_errors(argc, argv))
		ft_error();
	args_to_stack(argv, &a);
	print_stacks(a, b);
	ft_sa(&a);
	ft_rr(&a, &b);
	ft_rb(&b);
	ft_ra(&a);
	ft_rra(&a);
	ft_rrr(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_rra(&a);
	ft_ss(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_ra(&a);
	ft_ra(&a);
	ft_pa(&b, &a);
	ft_pa(&b, &a);
	ft_pa(&b, &a);
	ft_pa(&b, &a);
	ft_pa(&b, &a);
	print_stacks(a, b);
	ft_lstclear(&a, free);
}

void	print_stacks(t_list *a, t_list *b)
{
	int i;

	i = 0;
	ft_printf("|---a---|  |---b---|\n");
	while(a || b)
	{
		if (a)
		{
			ft_printf("|   %i   |  ", *(int *)(a->content));
			a = a->next;
		}
		else
			ft_printf("|   x   |  ");
		if (b)
		{
			ft_printf("|   %i   |\n", *(int *)(b->content));
			b = b->next;
		}
		else
			ft_printf("|   x   |\n");
	}
	ft_printf("|-------|  |-------|\n");
}

void	args_to_stack(char *argv[], t_list **stack)
{
	int	i;
	t_list	*temp;
	int *content;

	i = 1;
	while (argv[i])
	{
		content = safe_malloc(sizeof(int), *stack);
		*content = ft_atoi(argv[i]);
		temp = ft_lstnew(content);
		ft_lstadd_back(stack, temp);
		i++;
	}
}

void	ft_error()
{
	ft_printf("%s", "Error\n");
	exit(0);
}
