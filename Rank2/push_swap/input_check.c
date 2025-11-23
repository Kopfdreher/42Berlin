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
static int	strs_not_digits(char *argv[]);
static int	str_too_long(char *str);

int	input_has_errors(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (strs_not_digits(argv) || args_have_dups(argv))
			return (1);
		i++;
	}
	return (0);
}

static int	str_too_long(char *str)
{
	int	len;

	while (str[len])
		len++;
	return (len > 11);
}

static int	strs_not_digits(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (str_too_long(argv[i]))
			return (1);
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		j = 0;
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
