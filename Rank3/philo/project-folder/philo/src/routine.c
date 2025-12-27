/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:44:20 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 17:29:20 by sgavrilo         ###   ########.fr       */
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

int	thinking_routine(t_philo *philo)
{
	if (!print_thinking(philo))
		return (false);
	usleep(50);
	return (true);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->id % 2))
		usleep(1500);
	while (true)
	{
		if (!eating_routine(philo) || !sleeping_routine(philo)
			|| !thinking_routine(philo))
			return (arg);
	}
	return (arg);
}
