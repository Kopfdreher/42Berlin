/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:20:27 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:27:01 by sgavrilo         ###   ########.fr       */
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
		if (!args_are_valid(argv, &data))
			error_exit("Error: arguments not valid\n", 1);
		if (init_simulation(&data))
			free_exit("Error: initialization failed\n", &data, 1);
		monitor_routine(&data);
	}
	else
		error_exit("Error: wrong argument count\n", 1);
}
