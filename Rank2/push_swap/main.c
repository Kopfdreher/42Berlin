/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:11:49 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/23 21:47:08 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_error();
int		args_to_stack(char *argv[], t_list **stack);
void	print_stacks(t_list *a, t_list *b);
static void	turk_sort(t_list **a, t_list **b);
static void dump_sort(t_list **a, t_list **b);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 3 || input_has_errors(argc, argv))
		ft_error();
	
	if (!(args_to_stack(argv, &a)) || nums_have_dups(&a))
		ft_error();
	if (!(nums_sorted(&a)))
	{
		if (argc <= 6)
			dump_sort(&a, &b);
		else
			turk_sort(&a, &b);
	}
	ft_lstclear(&a, free);
}

static void dump_sort(t_list **a, t_list **b)
{
}

static void	turk_sort(t_list **a, t_list **b)
{
	sort_to_b(a, b);
	back_to_a(a, b);
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

int	args_to_stack(char *argv[], t_list **stack)
{
	int		i;
	t_list	*temp;
	int 	*content;
	long	check;

	i = 1;
	while (argv[i])
	{
		content = safe_malloc(sizeof(int), *stack);
		check = ft_atol(argv[i]);
		if (num_too_big(check))
			return (0);
		*content = (int)check;
		temp = ft_lstnew(content);
		ft_lstadd_back(stack, temp);
		i++;
	}
	return (1);
}

void	ft_error()
{
	ft_printf("%s", "Error\n");
	exit(0);
}

t_path	*new_path()
{
	t_path *new_path;

	new_path = malloc(sizeof(t_path));
	if (!new_path)
		return (NULL);
	new_path->num = 0;
	new_path->cost = 0;
	new_path->ra = 0;
	new_path->rb = 0;
	new_path->rra = 0;
	new_path->rrb = 0;
	new_path->size_a = 0;
	new_path->size_b = 0;
	return (new_path);
}
