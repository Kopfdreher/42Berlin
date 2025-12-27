/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:50:43 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 16:31:18 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_null(t_data *data)
{
	data->fork = NULL;
	data->philo = NULL;
}

static int	init_philos(t_data *data, int i)
{
	t_philo	*philo;

	philo = &data->philo[i];
	philo->data = data;
	philo->meals_eaten = 0;
	philo->last_meal_time = get_time();
	philo->id = i + 1;
	philo->left_fork = &data->fork[i];
	if (data->philo_count > 1)
		philo->right_fork = &data->fork[(i + 1) % data->philo_count];
	else
		philo->right_fork = NULL;
	if (pthread_create(&philo->thread, NULL, &philo_routine, philo))
		return (1);
	return (0);
}

int	init_simulation(t_data *data)
{
	int	i;

	init_null(data);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->fork)
		return (1);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_init(&data->fork[i], NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	data->philo = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philo)
		return (1);
	data->start_time = get_time();
	data->simulation_running = true;
	i = -1;
	while (++i < data->philo_count)
	{
		if (init_philos(data, i))
			return (1);
	}
	return (0);
}
