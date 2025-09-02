/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:53:16 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/11 13:02:46 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return(1);
	if (nb > 0)
		nb = nb * ft_recursive_factorial(nb-1);
	return(nb);
}
/*
int main(void)
{
	int	num = 9;

	printf("The Factorial of %d is %d", num, ft_recursive_factorial(num));
}
*/
