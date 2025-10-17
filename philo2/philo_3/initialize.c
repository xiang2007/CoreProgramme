/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:13:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/17 17:20:06 by wshou-xi         ###   ########.fr       */
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

void	init_mutex(t_args *arg, t_philo *philo)
{
	int	i;

	i = 0;
	arg->fork = malloc(sizeof(pthread_mutex_t) * arg->num_o_phi);
	while (i < arg->num_o_phi)
	{
		pthread_mutex_init(&arg->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&arg->m_meal, NULL);
	pthread_mutex_init(&arg->m_die, NULL);
	pthread_mutex_init(&arg->m_print, NULL);
}

int	initializer(char ac, char **av, t_args *ag, t_philo *phi)
{
	
}
