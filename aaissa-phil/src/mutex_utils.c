/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:34:50 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:35:58 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		write(2, "Error locking mutex\n", 20);
		exit(EXIT_FAILURE);
	}
}

void	unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		write(2, "Error unlocking mutex\n", 22);
		exit(EXIT_FAILURE);
	}
}

void	destroy_fork_mutexes(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_nb)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
}

void	destroy_global_mutexes(t_args *args)
{
	pthread_mutex_destroy(&args->print_mutex);
	pthread_mutex_destroy(&args->death_mutex);
	pthread_mutex_destroy(&args->meal_mutex);
}
