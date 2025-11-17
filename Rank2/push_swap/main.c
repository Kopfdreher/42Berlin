/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:41:02 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/15 12:25:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_error();

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		ft_error();
	i = 0;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_error()
{
	ft_printf("%s", "Error\n");
	exit(0);
}

