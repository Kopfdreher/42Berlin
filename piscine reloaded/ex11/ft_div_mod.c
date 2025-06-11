/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:03:40 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/09 18:13:12 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(void)
{
	int d = 0;
	int m = 0;
	int *div;
	int *mod;
	div = &d;
	mod = &m;
	ft_div_mod(4, 8, div, mod);
	printf("div: %d\nmod: %d\n", *div, *mod);
}
*/
