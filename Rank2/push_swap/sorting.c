/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:49:05 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/24 11:49:36 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void dump_sort(t_list **a, t_list **b)
{

}

void	turk_sort(t_list **a, t_list **b)
{
	sort_to_b(a, b);
	back_to_a(a, b);
}
