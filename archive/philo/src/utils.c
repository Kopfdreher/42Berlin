/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:44:40 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 20:19:17 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(char *str, int exitcode)
{
	if (str)
		printf("%s", str);
	exit(exitcode);
}

int	free_exit(char *str, t_data *data, int exitcode)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_join(data->philo[i].thread, NULL);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	free(data->fork);
	free(data->philo);
	if (str)
		printf("%s", str);
	exit(exitcode);
}

void	print_debug(char *str, t_data *data)
{
	pthread_mutex_lock(&data->write_lock);
	printf("%s", str);
	pthread_mutex_unlock(&data->write_lock);
}

int	still_running(void *ptr, int mode)
{
	t_philo	*philo;
	t_data	*data;

	if (mode == 0)
	{
		data = (t_data *)ptr;
		pthread_mutex_lock(&data->dead_lock);
		if (data->simulation_running)
		{
			pthread_mutex_unlock(&data->dead_lock);
			return (true);
		}
		pthread_mutex_unlock(&data->dead_lock);
		return (false);
	}
	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}
