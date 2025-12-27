/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:33 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 17:36:24 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	args_are_digits(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (false);
		}
	}
	return (true);
}

static int	convert_to_digits(char *argv[], t_data *data)
{
	long	digits[5];
	int		i;

	i = 0;
	while (argv[++i])
		digits[i - 1] = ft_atol(argv[i]);
	if (!data->meals_are_counted)
		digits[4] = 0;
	i = -1;
	while (++i < 4)
	{
		if (digits[i] <= 0 || digits[i] > INT_MAX)
			return (false);
	}
	if (data->meals_are_counted && (digits[4] < 0 || digits[4] > INT_MAX))
		return (false);
	data->philo_count = digits[0];
	data->time_to_die = digits[1];
	data->time_to_eat = digits[2];
	data->time_to_sleep = digits[3];
	data->limit_meals = digits[4];
	return (true);
}

int	args_are_valid(char *argv[], t_data *data)
{
	if (!args_are_digits(argv))
		return (false);
	if (!convert_to_digits(argv, data))
		return (false);
	return (true);
}
