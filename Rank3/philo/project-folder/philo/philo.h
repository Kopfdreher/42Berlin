/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:23:18 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/17 22:28:11 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_data {
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meal_goal;
	bool	meals_are_counted;
}	t_data;

int	error_exit(char *str, int errorcode);
int args_are_valid(char *argv[], t_data *data);
long	ft_atol(const char *str);

#endif
