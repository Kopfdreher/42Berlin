/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 17:44:42 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_taken_fork(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		time = get_time() - philo->data->start_time;
		printf("%lld %i has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}

int	print_eating(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		time = get_time() - philo->data->start_time;
		printf("%lld %i is eating\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}

int	print_sleeping(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		time = get_time() - philo->data->start_time;
		printf("%lld %i is sleeping\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}

int	print_thinking(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		time = get_time() - philo->data->start_time;
		printf("%lld %i is thinking\n", time, philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (false);
}
