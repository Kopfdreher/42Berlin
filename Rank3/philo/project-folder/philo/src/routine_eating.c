/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:41:20 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 17:15:43 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	lock_forks(pthread_mutex_t *fork_a, pthread_mutex_t *fork_b)
{
	pthread_mutex_lock(fork_a);
	pthread_mutex_lock(fork_b);
}

static void	unlock_forks(pthread_mutex_t *fork_a, pthread_mutex_t *fork_b)
{
	pthread_mutex_unlock(fork_a);
	pthread_mutex_unlock(fork_b);
}

int	eating_routine(t_philo *philo)
{
	if (philo->data->philo_count > 1)
	{
		if (philo->id % 2)
			lock_forks(philo->left_fork, philo->right_fork);
		else
			lock_forks(philo->right_fork, philo->left_fork);
		if (!print_eating(philo))
			return (unlock_forks(philo->right_fork, philo->left_fork), false);
		pthread_mutex_lock(&philo->data->meal_lock);
		philo->last_meal_time = get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_lock);
		smart_usleep(philo->data->time_to_eat);
		return (unlock_forks(philo->right_fork, philo->left_fork), true);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (false);
	}
}
