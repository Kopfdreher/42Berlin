/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:07 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:49:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor_routine(t_data *data)
{
	int	i;
	int	meals_min;

	while (true)
	{
		i = -1;
		meals_min = 0;
		while (++i < data->philo_count)
		{
			pthread_mutex_lock(&data->meal_lock);
			if ((get_time() - data->philo[i].last_meal_time)
				> data->time_to_die)
			{
				pthread_mutex_lock(&data->dead_lock);
				data->simulation_running = false;
				pthread_mutex_unlock(&data->dead_lock);
			}
			if (data->philo[i].meals_eaten >= data->limit_meals)
				meals_min++;
			pthread_mutex_unlock(&data->meal_lock);
		}
		if (data->meals_are_counted && meals_min == data->philo_count)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->simulation_running = false;
			pthread_mutex_unlock(&data->dead_lock);
		}
		pthread_mutex_lock(&data->dead_lock);
		if (!data->simulation_running)
		{
			pthread_mutex_unlock(&data->dead_lock);
			free_exit("Finished\n", data, 0);
		}
		usleep(1000);
	}
}
