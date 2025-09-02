/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:51:40 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:29 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
/*
int main(void)
{
	int anumber = 42;
	int bnumber = 24;
	int *a;
	int *b;
	a = &anumber;
	b = &bnumber;
	ft_swap(a, b);
	printf("a: %d\nb: %d\n", *a, *b);
}
*/
