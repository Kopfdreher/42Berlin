/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:55:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/19 19:55:47 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>


typedef struct s_path
{
	int	num;
	int	cost;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	size_a;
	int	size_b;
}	t_path;

/* Sorting Functions */
void	turk_sort(t_list **a, t_list **b);
void 	dump_sort(t_list **a, t_list **b);

/* Input Handling */
int		input_has_errors(int argc, char *argv[]);
int		nums_have_dups(t_list **a);
long	num_too_big(long num);
int		nums_sorted(t_list **a);
void	print_stacks(t_list *a, t_list *b);
void	ft_error();
int		args_to_stack(char *argv[], t_list **stack);
void	print_stacks(t_list *a, t_list *b);
void	free_strarr(char *argv[]);
void	input_check(char *argv[], t_list **a, int args_allocated);

/* Helper Functions */
void	*safe_malloc(size_t size, t_list *stack);
void	movement_table(t_path *path, t_list **a, t_list **b);
void	sort_to_b(t_list **a, t_list **b);
int		find_rotations(int num, t_list **a);
void	back_to_a(t_list **a, t_list **b);
t_path	*new_path();

/* Swap Functions */
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_sb(t_list **stack);
void	ft_sa(t_list **stack);

/* Push Functions */
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);

/* Rotate Functions */
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

#endif
