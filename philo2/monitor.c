/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:34:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/17 14:44:26 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	check_death(t_philo *phi)
{
	int		res;
	t_args	*ag;

	res = 0;
	ag = phi->arg;
	lock_mutex(&ag->m_meal);
	if (phi->finished)
		return (unlock_mutex(&ag->m_meal), 0);
	if ((gettime() - phi->last_eaten) > ag->die_time)
	{
		lock_mutex(&ag->m_die);
		ag->stop = 1;
		lock_mutex(&ag->m_print);
		printf("%lld %d died\n", gettime() - ag->start_time, phi->id);
		unlock_mutex(&ag->m_print);
		unlock_mutex(&ag->m_die);
		res = 1;
	}
	unlock_mutex(&ag->m_meal);
	return (res);
}

int	check_philo(t_philo *philo)
{
	t_args	*ag;
	int		i;
	int		satisfied;

	ag = philo->arg;
	satisfied = 1;
	i = 0;
	while (i < ag->num_o_phi)
	{
		if (check_death(&philo[i]))
			return (1);
		lock_mutex(&ag->m_meal);
		if (ag->must_eat > 0 && philo->meals_eaten <= ag->must_eat)
			satisfied = 0;
		unlock_mutex(&ag->m_meal);
		i++;
	}
	if (ag->must_eat > 0 && satisfied)
	{
		ag->all_satisfied = 1;
		return (printf("All philo finished eating!!\n"), 2);
	}
	return (0);
}

void	*monitor_routine(void *philo)
{
	int		flag;
	t_philo	*phi;
	t_args	*ag;

	phi = (t_philo *)philo;
	ag = phi->arg;
	while (!ag->stop)
	{
		flag = check_philo(phi);
		if(flag == 1 || flag == 2)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	start_monitor(t_philo *philo)
{
	pthread_t	monitor_thread;
	int			i;

	i = 0;
	if (pthread_create(&monitor_thread, NULL, monitor_routine, (void *)philo) != 0)
	{
		lock_mutex(&philo->arg->m_die);
		philo->arg->stop = 1;
		unlock_mutex(&philo->arg->m_die);
		printf("Monitor thread creation failed\n");
		while (i < philo->arg->num_o_phi)
		{
			pthread_join(philo[i].thread_id, NULL);
			i++;
		}
		return (1);
	}
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < philo->arg->num_o_phi)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}
