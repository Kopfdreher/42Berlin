/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 20:23:57 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		printf("%lld %i has taken a fork\n", get_time(), philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (false);
}

int	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		printf("%lld %i is eating\n", get_time(), philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (false);
}

int	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		printf("%lld %i is sleeping\n", get_time(), philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (false);
}

int	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		printf("%lld %i is thinking\n", get_time(), philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (false);
}

int	print_dieing(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->simulation_running)
	{
		printf("%lld %i died\n", get_time(), philo->id);
		pthread_mutex_unlock(&philo->data->dead_lock);
		pthread_mutex_unlock(&philo->data->write_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_mutex_unlock(&philo->data->write_lock);
	return (false);
}
