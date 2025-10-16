/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:34:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/16 17:39:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	all_satisfied(t_args *ag, t_philo *phi);

int	check_death(t_2l c_time, t_philo *phi, t_args *ag)
{
	int	i;
	int	meals_satisfied;

	i = 0;
	meals_satisfied = 0;
	while (i < ag->num_o_phi)
	{
		if (c_time - phi[i].last_eaten < ag->die_time)
		{
			lock_mutex(&ag->die);
			lock_mutex(&ag->print);
			printf("[%lld]\tPhilo %d died\n", c_time, phi->id);
			unlock_mutex(&ag->print);
			unlock_mutex(&ag->die);
			return (1);
		}
		if (all_satisfied(ag, phi))
			meals_satisfied = 1;
		i++;
	}
	if (meals_satisfied)
		return (2);
	return (0);
}

int	all_satisfied(t_args *ag, t_philo *phi)
{
	int	i;

	i = 0;
	while (i < ag->num_o_phi)
	{
		if (phi[i].meals_eaten < ag->must_eat)
			return (0);
		i++;
	}
	lock_mutex(&ag->print);
	printf("[%lld]\tAll philo satisfied\n", (gettime() - ag->start_time));
	unlock_mutex(&ag->print);
	return (1);
}

int	monitor_thread(t_args *ag, t_philo *phi)
{
	t_2l	c_time;
	int		flag;

	while (1)
	{
		c_time = gettime() - ag->start_time;
		flag = check_death(c_time, phi, ag);
		if (flag == 1)
			return (1);
		if (flag == 2)
			return (2);
		usleep(100);
	}
	return (0);
}