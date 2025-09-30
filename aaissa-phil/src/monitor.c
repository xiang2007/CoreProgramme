/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:24:52 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:34:24 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philos *philo)
{
	t_args	*args;
	int		result;

	args = philo->args;
	result = 0;
	lock(&args->meal_mutex);
	if (philo->finish_meals)
		return (unlock(&args->meal_mutex), 0);
	if ((get_current_time() - philo->last_meal_time) > args->t_to_die)
	{
		lock(&args->death_mutex);
		args->is_died = 1;
		lock(&args->print_mutex);
		printf("%ld %d died 💀\n", get_current_time()
			- args->start_time, philo->id);
		unlock(&args->print_mutex);
		unlock(&args->death_mutex);
		result = 1;
	}
	unlock(&args->meal_mutex);
	return (result);
}

int	check_philos(t_philos *philos)
{
	t_args	*args;
	int		i;
	int		finished_eating;

	args = philos[0].args;
	i = 0;
	finished_eating = 1;
	while (i < args->philos_nb)
	{
		if (check_death(&philos[i]))
			return (1);
		lock(&args->meal_mutex);
		if (args->must_eat_count != -1 && philos[i].meals_eaten
			< args->must_eat_count)
			finished_eating = 0;
		unlock(&args->meal_mutex);
		i++;
	}
	if (args->must_eat_count != -1 && finished_eating)
	{
		args->all_satisfied = 1;
		return (printf("\033[0;33mAll philos have eaten %d meals\033[0m\n",
				args->must_eat_count), 2);
	}
	return (0);
}

void	*m_routine(void *philo)
{
	t_philos		*philos;
	t_args			*args;
	int				status;

	philos = (t_philos *)philo;
	args = philos[0].args;
	while (!args->is_died)
	{
		status = check_philos(philos);
		if (status == 1)
			return (NULL);
		if (status == 2)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	monitor(t_args *args, t_philos *philo)
{
	pthread_t	monitor_thread;
	int			i;

	if (pthread_create(&monitor_thread, NULL, m_routine, (void *)philo) != 0)
	{
		printf("Error: Monitor thread creation failed\n");
		lock(&args->death_mutex);
		args->stop_threads = 1;
		unlock(&args->death_mutex);
		i = 0;
		while (i < args->philos_nb)
		{
			pthread_join(philo[i].thread_id, NULL);
			i++;
		}
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < args->philos_nb)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}
