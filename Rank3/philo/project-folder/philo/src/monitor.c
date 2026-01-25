/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:07 by sgavrilo          #+#    #+#             */
/*   Updated: 2026/01/23 15:32:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->simulation_running = false;
	pthread_mutex_unlock(&data->dead_lock);
}

void	died_routine(t_data *data, int i)
{
	long long	time;

	pthread_mutex_lock(&data->dead_lock);
	time = get_time() - data->start_time;
	printf("%lld %i died\n", time, i + 1);
	data->simulation_running = false;
	pthread_mutex_unlock(&data->dead_lock);
	pthread_mutex_unlock(&data->meal_lock);
}

int	monitor_routine(t_data *data)
{
	int			i;
	int			meals_min;

	while (true)
	{
		if (data->meals_are_counted && data->limit_meals == 0)
			return (stop_simulation(data), 0);
		i = -1;
		meals_min = 0;
		while (++i < data->philo_count)
		{
			pthread_mutex_lock(&data->meal_lock);
			if ((get_time() - data->philo[i].last_meal_time)
				> data->time_to_die)
				return (died_routine(data, i), 0);
			if (data->meals_are_counted
				&& (data->philo[i].meals_eaten >= data->limit_meals))
				meals_min++;
			pthread_mutex_unlock(&data->meal_lock);
		}
		if (data->meals_are_counted && meals_min == data->philo_count)
			return (stop_simulation(data), 0);
		usleep(100);
	}
}
