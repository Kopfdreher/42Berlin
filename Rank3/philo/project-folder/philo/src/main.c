/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:20:27 by sgavrilo          #+#    #+#             */
/*   Updated: 2026/01/23 16:06:21 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (argc == 6)
			data.meals_are_counted = true;
		else
			data.meals_are_counted = false;
		if (!args_are_valid(argv, &data))
			error_exit("Error: arguments not valid\n", 1);
		if (data.meals_are_counted && data.limit_meals == 0)
			error_exit("", 0);
		if (init_simulation(&data))
			free_exit("Error: initialization failed\n", &data, 1);
		monitor_roudine(&data);
		free_exit(NULL, &data, 0);
	}
	else
		error_exit("Error: wrong argument count\n", 1);
}
