/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:48:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/15 18:11:25 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	asign_arguments(int ac, char **av, t_args *ag)
{
	if (ac == 6)
	{
		ag->must_eat = ft_atoi(av[5]);
		ag->all_satisfied = 0;
	}
	else
	{
		ag->must_eat = -1;
		ag->all_satisfied = -1;
	}
	ag->num_o_phi = ft_atoi(av[1]);
	ag->sleep_time = ft_atoi(av[4]);
	ag->eat_time = ft_atoi(av[3]);
	ag->die_time = ft_atoi(av[2]);
	ag->stop = 0;
}

int	checkarg(int ac, t_args *ag)
{
	if (ac == 6 && ag->must_eat < 1)
		return (printf("Number of meals must bigger than 1\n"), 1);
	if (ag->die_time <= 0)
		return (printf("Die time must above 1ms\n"), 1);
	if (ag->eat_time <= 0)
		return (printf("Eat time must above 1ms\n"), 1);
	if (ag->num_o_phi <= 0)
		return (printf("Number of philo must above 1\n"), 1);
	if (ag->sleep_time <= 0)
		return (printf("Sleep time must above 1ms\n"), 1);
	return (2);
}

t_philo	*init_philos(t_args *arg)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * arg->num_o_phi);
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->num_o_phi);
	while (i < arg->num_o_phi)
	{
		if (pthread_mutex_init(&arg->fork[i], NULL) != 0)
			return (NULL);
		i++;
	}
	pthread_mutex_init(&arg->print, NULL);
	i = 0;
	while(i < arg->num_o_phi)
	{
		philo[i].id = i + 1;
		philo[i].died = 0;
		philo[i].last_eaten = gettime();
		philo[i].last_sleep = 0;
		philo[i].meals_eaten = 0;
		i++;
	}
	return (philo);
}

t_philo	*parse(int ac, char **av, t_args *ag)
{
	t_philo *philo;

	philo = NULL;
	if (ac >= 5 && ac <= 6)
	{
		asign_arguments(ac, av, ag);
		if (checkarg(ac, ag) != 2)
			return (NULL);
		philo = init_philos(ag);
	}
	return (philo);
}