/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:53:47 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/19 19:53:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2);
static int	args_have_dups(char *argv[]);
static int	str_is_digit(char *str);


int	input_has_errors(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (args_have_dups(argv))
			return (1);
		i++;
	}
	return (0);
}

static int	args_have_dups(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
