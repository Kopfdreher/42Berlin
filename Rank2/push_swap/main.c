/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:11:49 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 12:02:35 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_error();
int		args_to_stack(char *argv[], t_list **stack);
void	print_stacks(t_list *a, t_list *b);
void	free_strarr(char *argv[]);
void	input_check(char *argv[], t_list **a, int args_allocated);

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	**one_arg;

	a = NULL;
	b = NULL;
	one_arg = NULL;
	if (argc == 2)
	{
		one_arg = ft_split(argv[1], ' ');
		input_check(one_arg, &a, 1);
	}
	else if (argc > 3)
		input_check(&argv[1], &a, 0);
	else
		ft_error();
	if (!(nums_sorted(&a)))
	{
		if (ft_lstsize(a) <= 5)
			dump_sort(&a, &b);
		else
			turk_sort(&a, &b);
	}
	if (one_arg)
		free_strarr(one_arg);
	ft_lstclear(&a, free);
}

void	free_strarr(char *argv[])
{
	int	i;
	
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	input_check(char *argv[], t_list **a, int args_allocated)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc < 2 || input_has_errors(argc, argv))
	{
		if (args_allocated)
			free_strarr(argv);
		ft_error();
	}
	if (!(args_to_stack(argv, a)) || nums_have_dups(a))
		if (args_allocated)
			free_strarr(argv);
		ft_error();
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

	i = 0;
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
	exit(1);
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
