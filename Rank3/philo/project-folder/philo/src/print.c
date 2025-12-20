/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:53:54 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_lock);
	printf("%lld %i has taken a fork\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->data->write_lock);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_lock);
	printf("%lld %i is eating\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->data->write_lock);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_lock);
	printf("%lld %i is sleeping\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->data->write_lock);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_lock);
	printf("%lld %i is thinking\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->data->write_lock);
}

void	print_dieing(t_philo *philo)
{
	pthread_mutex_lock(philo->data->write_lock);
	printf("%lld %i died\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->data->write_lock);
}
