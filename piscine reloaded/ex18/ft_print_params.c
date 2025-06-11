/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:44:51 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/11 14:26:44 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc >= 1)
	{
		i = 1;
		while (i <= argc-1)
		{
			ft_putstr(argv[i]);
			i++;
		}
	}
}
