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

typedef struct s_path
{
	int				value;
	int				cost;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_path	*next;
}	t_path;

/* Helper Functions */
void	*safe_malloc(size_t size, t_list *stack);
int		input_has_errors(int argc, char *argv[]);

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
