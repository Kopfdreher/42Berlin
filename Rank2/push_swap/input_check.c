/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:53:47 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/19 19:53:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	input_check(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!str_is_digit(argv[argc]))
			return (0);
	}
}

static int	str_is_digit(char *str)
{
	int	i;

		
}

static int	ft_strcmp(const char *s1, const char *s2)
{
}
