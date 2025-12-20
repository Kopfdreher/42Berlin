/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:23:18 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/20 17:55:15 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo t_philo;

typedef struct s_data {
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit_meals;
	bool			meals_are_counted;
	long long		start_time;
	bool			simulation_running;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philo;
}	t_data;

typedef struct s_philo {
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	t_data			*data;
}	t_philo;

/* Exit */
int	free_exit(char *str, t_data *data, int exitcode);
int	error_exit(char *str, int exitcode);

/* Parsing */
int args_are_valid(char *argv[], t_data *data);
long	ft_atol(const char *str);

/* Initialize */
int	init_simulation(t_data *data);

/* Time */
long long	get_time(void);
void		smart_usleep(long long time_to_wait);

/* Routines */
void	*philo_routine(void *philo);
void	monitor_routine(t_data *data);

/* Printing */
void	print_taken_fork(t_philo *philo);
void	print_eating(t_philo *philo);
void	print_sleeping(t_philo *philo);
void	print_thinking(t_philo *philo);
void	print_dieing(t_philo *philo);

#endif
