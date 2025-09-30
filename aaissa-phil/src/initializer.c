/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:20:20 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:21:41 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_args *args, int argc, char **argv)
{
	args->philos_nb = ft_atoi(argv[1]);
	args->t_to_die = ft_atoi(argv[2]);
	args->t_to_eat = ft_atoi(argv[3]);
	args->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->must_eat_count = ft_atoi(argv[5]);
	else
		args->must_eat_count = -1;
	args->is_died = 0;
	args->start_time = 0;
	args->stop_threads = 0;
	args->all_satisfied = 0;
	if (validate_arguments(args, argc) != 0)
		return (1);
	return (0);
}

int	init_forks(t_args *args)
{
	int	i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_nb);
	if (!args->forks)
		return (printf("Error: Memory allocation failed\n"), 1);
	while (i < args->philos_nb)
	{
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			return (printf("Error: Mutex initialization failed\n"), 1);
		i++;
	}
	return (0);
}

int	init_global_mutexes(t_args *args)
{
	if (pthread_mutex_init(&args->death_mutex, NULL) != 0)
		return (printf("Error: Mutex initialization failed\n"), 1);
	if (pthread_mutex_init(&args->meal_mutex, NULL) != 0)
		return (printf("Error: Mutex initialization failed\n"), 1);
	if (pthread_mutex_init(&args->print_mutex, NULL) != 0)
		return (printf("Error: Mutex initialization failed\n"), 1);
	return (0);
}

int	init_philo(t_philos **philos, t_args *args)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philos) * args->philos_nb);
	if (!(*philos))
		return (printf("Error: Memory allocation failed\n"), 1);
	while (i < args->philos_nb)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].l_fork = i;
		(*philos)[i].r_fork = (i + 1) % args->philos_nb;
		(*philos)[i].last_meal_time = 0;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].args = args;
		(*philos)[i].finish_meals = 0;
		i++;
	}
	return (0);
}

int	initializer(t_args *args, t_philos **philos, int argc, char **argv)
{
	if (init_args(args, argc, argv) != 0)
		return (1);
	if (init_global_mutexes(args) != 0)
		return (1);
	if (init_forks(args) != 0)
		return (destroy_global_mutexes(args), 1);
	if (init_philo(philos, args) != 0)
	{
		destroy_fork_mutexes(args);
		free(args->forks);
		destroy_global_mutexes(args);
		return (1);
	}
	return (0);
}
