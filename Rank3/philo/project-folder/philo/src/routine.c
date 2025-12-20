/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:44:20 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:55:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		smart_usleep(philo->data.time_to_sleep);
		pthread_mutex_lock(&philo->data->dead_lock);
		if (!philo->data->simulation_running)
		{
			pthread_mutex_unlock(&philo->data->dead_lock);
			return (arg);
		}
	}
	return (arg);
}
