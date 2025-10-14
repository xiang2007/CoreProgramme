/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:48:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/14 17:15:57 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	asign_arguments(int ac, char **av, t_args *ag)
{
	int	i;

	i = 0;
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
	ag->fork = malloc(sizeof(int) * ag->num_o_phi);
	while (i < ag->num_o_phi)
	{
		ag->fork[i] = i;
		i++;
	}
}

int	checkarg(int ac, char **av, t_args *ag)
{
	if (ac == 6 && ag->must_eat < 1)
		return (printf("Number of meals must bigger than 1\n"), 1);
	if (ag->die_time < 0)
		return (printf("Die time must above 1ms\n", 1));
	if (ag->eat_time < 0)
		return (printf("Eat time must above 1ms\n",1 ));
	if (ag->num_o_phi < 0)
		return (printf("Number of philo must above 1\n", 1));
	if (ag->sleep_time < 0)
		return (printf("Sleep time must above 1ms\n", 1));
	return (2);
}

t_philo	*init_philos(t_args arg)
{
	int	i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * arg.num_o_phi);
	while(i < arg.num_o_phi)
	{
		philo[i].id = i + 1;
		philo[i].died = 0;
		philo[i].last_eaten = 0;
		philo[i].last_sleep = 0;
		philo[i].left_fork = 0;
		philo[i].right_fork = 0;
		philo[i].meals_eaten = 0;
		i++;
	}
	return (philo);
}

int	parse(int ac, char **av, t_args *ag, t_philo *phi)
{
	if (ac >= 5 && ac <= 6)
	{
		if (!checknums(av))
			return (0);
		asign_arguments(ac, av, ag);
		if (checkarg(ac, av, ag) != 2)
			return (1);
	}
}