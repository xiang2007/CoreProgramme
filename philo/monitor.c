/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:36:57 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/19 16:23:58 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all_sat(t_philo *phi)
{
	lock_mutex(&phi->arg->m_print);
	printf("All philo satisfied!!\n");
	unlock_mutex(&phi->arg->m_print);
}

int	check_philo_death(t_philo *phi)
{
	t_args	*ag;
	t_2l	current_time;
	t_2l	last_meal;

	ag = phi->arg;
	lock_mutex(&ag->m_meal);
	if (ag->all_satisfied)
		return (unlock_mutex(&ag->m_meal), 0);
	current_time = gettime();
	last_meal = current_time - phi->last_eaten;
	unlock_mutex(&ag->m_meal);
	if (last_meal > ag->die_time)
	{
		lock_mutex(&ag->m_die);
		ag->stop = 1;
		unlock_mutex(&ag->m_die);
		lock_mutex(&ag->m_print);
		printf("%lld\t %d died\n", gettime() - ag->start_time, phi->id);
		unlock_mutex(&ag->m_print);
		return (1);
	}
	return (0);
}

int	monitor_cycle(t_philo *philo)
{
	t_args	*ag;
	int		i;
	int		satisfied;

	ag = philo->arg;
	i = 0;
	satisfied = 1;
	while (i < ag->num_o_phi)
	{
		if (check_philo_death(&philo[i]))
			return (1);
		lock_mutex(&ag->m_meal);
		if (ag->must_eat != -1 && philo[i].meals_eaten < ag->must_eat)
			satisfied = 0;
		unlock_mutex(&ag->m_meal);
		i++;
	}
	if (ag->must_eat != -1 && satisfied)
	{
		lock_mutex(&ag->m_die);
		ag->all_satisfied = 1;
		unlock_mutex(&ag->m_die);
		return ((print_all_sat(philo)), 1);
	}
	return (0);
}

void	*monitor_routine(void *philo)
{
	t_philo	*phi;
	t_args	*ag;
	int		status;

	phi = (t_philo *)philo;
	ag = phi->arg;
	while (!ag->stop)
	{
		status = monitor_cycle(phi);
		if (status)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	start_monitor(t_args *ag, t_philo *phi)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	if (pthread_create(&monitor, NULL, monitor_routine, (void *)phi) != 0)
	{
		printf("Monitor thread creation failed!\n");
		lock_mutex(&ag->m_die);
		ag->stop = 1;
		unlock_mutex(&ag->m_die);
		while (i < ag->num_o_phi)
		{
			pthread_join(phi[i].thread_id, NULL);
			i++;
		}
		return (1);
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < ag->num_o_phi)
	{
		pthread_join(phi[i].thread_id, NULL);
		i++;
	}
	return (0);
}
