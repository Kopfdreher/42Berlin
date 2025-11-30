/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:54:14 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/20 16:54:15 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	*safe_malloc(size_t size, t_list *stack)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Fatal Error: Memory allocation failed\n", 2);
		ft_lstclear(&stack, free);
		exit(1);
	}
	return (ptr);
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

void	print_stacks(t_list *a, t_list *b)
{
	ft_printf("|---a---|  |---b---|\n");
	while (a || b)
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

void	ft_exit(t_list **a)
{
	if (*a)
		ft_lstclear(a, free);
	exit(0);
}

void	ft_error(t_list **a)
{
	ft_printf("%s", "Error\n");
	ft_lstclear(a, free);
	exit(1);
}
