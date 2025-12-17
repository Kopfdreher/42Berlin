/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:21:01 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/17 20:37:05 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	smart_usleep(long long time_to_wait)
{
	long long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() == start_time) < time_to_wait)
		usleep(500);
}

typedef struct s_data {
	int				mails;
	int				id;
	int				start_time;
	pthread_mutex_t	mutexmails;
	pthread_mutex_t	mutexid;
	pthread_mutex_t	write_lock;
}	t_data;

void	write_status(char *str, t_data *data)
{
	long long	time;

	pthread_mutex_lock(&data->write_lock);
	time = get_time_in_ms() - data->start_time;
	printf("%lld %i, %s\n", time, data->id, str);
	pthread_mutex_unlock(&data->write_lock);
}

void	*routine(void *arg) {
	int		i;
	t_data	*data;
	int		id;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->mutexid);
	id = data->id;
	data->id++;
	pthread_mutex_unlock(&data->mutexid);
	i = -1;
	write_status("Thread %i starting to count at %i.\n", data);
	while (++i < 1000000)
	{
		pthread_mutex_lock(&data->mutexmails);
		data->mails++;
		pthread_mutex_unlock(&data->mutexmails);
	}
	write_status("Thread %i ended counting at %i.\n", data);
	return (arg);
}

int	main(void)
{
	pthread_t	*threads;
	t_data		data;
	int			i;
	int			thread_count = 4;

	data.mails = 0;
	data.id = 0;
	pthread_mutex_init(&data.mutexmails, NULL);
	pthread_mutex_init(&data.mutexid, NULL);
	pthread_mutex_init(&data.write_lock, NULL);
	data.start_time = get_time_in_ms();
	threads = malloc(sizeof(pthread_t *) * thread_count);
	if (!threads)
		return (1);
	i = -1;
	while (++i < thread_count)
	{
		if (pthread_create(&threads[i], NULL, &routine, &data))
			return (1);
	}
	i = -1;
	while (++i < thread_count)
	{
		if (pthread_join(threads[i], NULL))
			return (1);
	}
	pthread_mutex_destroy(&data.mutexmails);
	pthread_mutex_destroy(&data.mutexid);
	pthread_mutex_destroy(&data.write_lock);
	free(threads);
	printf("%i", data.mails);
	return (0);
}
