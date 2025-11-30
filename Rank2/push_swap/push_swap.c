/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:11:49 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 20:32:19 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	else if (argc > 2)
		input_check(&argv[1], &a, 0);
	if (a && !(nums_sorted(&a)))
	{
		if (ft_lstsize(a) <= 5)
			dump_sort(&a, &b);
		else
			turk_sort(&a, &b);
	}
	if (one_arg)
		free_strarr(one_arg);
	ft_exit(&a);
}

int	args_to_stack(char *argv[], t_list **stack)
{
	int		i;
	t_list	*temp;
	int		*content;
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
