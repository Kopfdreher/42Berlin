/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:45:33 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/17 22:35:04 by sgavrilo         ###   ########.fr       */
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

	digits[4] = 0;
	i = 0;
	while (argv[++i])
		digits[i] = ft_atol(argv[i + 1]);

	i = -1;
	while (digits[++i])
		digits[i] = ft_atol(argv[i + 1]);
	data->num_of_philos = digit[0];
	data->time_to_die = digit[1];
	data->time_to_eat = digit[2];
	data->time_to_sleep = digit[3];
	if (data->meals_are_counted)
		data->meal_goal = digit[4];
	return (true);
}

int args_are_valid(char *argv[], t_data *data)
{
	if (!args_are_digits(argv))
		return (false);
	//if (!convert_to_digits(argv, data))
	//	return (false);
	return (true);
}
