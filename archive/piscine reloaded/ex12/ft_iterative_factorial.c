/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:15:13 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/11 12:33:32 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb <= 0)
	{
		return(0);
	}
	while (nb > 0)
	{
		factorial = nb * factorial;
		nb--;
	}
	return(factorial);
}

int main(void)
{
	int num = 8;
	printf("The Factorial of %d is %d\n", num, ft_iterative_factorial(num));
}
