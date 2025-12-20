/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:44:20 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 20:21:44 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping_routine(t_philo *philo)
{
	if (!print_sleeping(philo))
		return (false);
	smart_usleep(philo->data->time_to_sleep);
	return (true);
}

int	eating_routine(t_philo *philo)
{
	if (!print_eating(philo))
		return (false);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	smart_usleep(philo->data->time_to_eat);
	return (true);
}

int	thinking_routine(t_philo *philo)
{
	if (!print_thinking(philo))
		return (false);
	smart_usleep(10);
	return (true);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (!eating_routine(philo) || !sleeping_routine(philo)
			|| !thinking_routine(philo))
			return (arg);
	}
	return (arg);
}
