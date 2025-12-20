/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:07 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 20:06:26 by sgavrilo         ###   ########.fr       */
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
				return ;
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
			print_debug("Eaten enough\n", data);
			return ;
		}
		if (!still_running(data, 0))
			return ;
		pthread_mutex_unlock(&data->dead_lock);
		usleep(1000);
	}
}
