/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:37:06 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:37:54 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;
	long			time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

void	ft_usleep(long time_in_ms)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < time_in_ms)
		usleep(500);
}

void	print(t_philos *philo, char *message)
{
	lock(&philo->args->meal_mutex);
	lock(&philo->args->death_mutex);
	if (!philo->args->is_died)
	{
		unlock(&philo->args->death_mutex);
		lock(&philo->args->print_mutex);
		printf("%ld %d %s\n", get_current_time()
			- philo->args->start_time, philo->id, message);
		unlock(&philo->args->print_mutex);
	}
	else
		unlock(&philo->args->death_mutex);
	unlock(&philo->args->meal_mutex);
}

void	clean_up(t_args *args, t_philos *philos)
{
	destroy_fork_mutexes(args);
	destroy_global_mutexes(args);
	free(args->forks);
	free(philos);
}
