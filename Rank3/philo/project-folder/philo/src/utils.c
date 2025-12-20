/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:44:40 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:01:01 by sgavrilo         ###   ########.fr       */
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
