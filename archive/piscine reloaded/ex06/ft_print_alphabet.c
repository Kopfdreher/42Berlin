/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:31:57 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/07 15:58:44 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_alphabet(void)
{
	char i;
	i = 'a';
	while (i <= 'z')
	{
		ft_putchar(i);
		i++;
	}
}

int main(void)
{
	ft_print_alphabet();
	return 0;
}

