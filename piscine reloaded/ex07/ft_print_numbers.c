/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:06:17 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/07 16:11:44 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_numbers(void)
{
	char i;
	i = '0';
	while (i <= '9')
	{
		ft_putchar(i);
		i++;
	}
}

int main(void)
{
	ft_print_numbers();
}
