/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:21:55 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:24:34 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_start_philos(t_args *args, t_philos *philos)
{
	int	i;

	i = 0;
	args->start_time = get_current_time();
	while (i < args->philos_nb)
	{
		philos[i].last_meal_time = args->start_time;
		if (pthread_create(&philos[i].thread_id, NULL,
				routine, (void *)&philos[i]) != 0)
			return (printf("Error: Thread creation failed\n"), 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_args			args;
	t_philos		*philos;

	if (ac < 5 || ac > 6)
		return (printf("Error: Invalid number of arguments\n"), 1);
	if (check_arguments(ac, av))
		return (1);
	if (initializer(&args, &philos, ac, av) != 0)
		return (1);
	if (create_start_philos(&args, philos) != 0)
		return (clean_up(&args, philos), 1);
	if (monitor(&args, philos) != 0)
		return (clean_up(&args, philos), 1);
	clean_up(&args, philos);
	return (0);
}
