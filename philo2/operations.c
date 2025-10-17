/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:36:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/17 16:49:20 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	p_eat(t_philo *phi)
{
	t_args	*ag;

	ag = phi->arg;
	if (phi->id % 2 == 0)
	{
		lock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
		print(phi, "has taken a fork");
		lock_mutex(&ag->fork[phi->id + 1]);
		print(phi, "has taken a fork");
	}
	else
	{
		lock_mutex(&ag->fork[phi->id + 1]);
		print(phi, "has taken a fork");
		lock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
		print(phi, "has taken a fork");
	}
	lock_mutex(&ag->m_meal);
	phi->last_eaten = gettime();
	phi->meals_eaten++;
	print(phi, "is eating");
	usleep(ag->eat_time * 1000);
	unlock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
	unlock_mutex(&ag->fork[phi->id + 1]);
}

void	p_sleep_think(t_args *ag, t_philo *phi)
{
	print(phi, "is sleeping");
	usleep(ag->sleep_time * 1000);
	print(phi, "is thinking");
	if (ag->num_o_phi % 2 == 1)
		usleep(100);
}

void	cycle(t_philo *philo)
{
	t_args	*ag;

	ag = philo->arg;
	while (1)
	{
		lock_mutex(&ag->m_die);
		if (ag->stop || ag->all_satisfied || philo->died)
		{
			unlock_mutex(&ag->m_die);
			break ;
		}
		p_eat(philo);
		lock_mutex(&ag->m_die);
		if (ag->must_eat != -1 && philo->meals_eaten >= ag->must_eat)
		{
			philo->finished = 1;
			unlock_mutex(&ag->m_die);
			break ;
		}
		unlock_mutex(&ag->m_meal);
		p_sleep_think(ag, philo);
	}
}

void	one_philo(t_philo *philo)
{
	print(philo, "pick up a fork");
	usleep(philo->arg->die_time);
	printf("%lld %d died\n", gettime(), philo->id);
	philo->died = 1;
}

void	*p_routine(void *philo)
{
	t_philo	*phi;

	phi = (t_philo *)philo;
	lock_mutex(&phi->arg->m_die);
	if (phi->arg->stop)
		return (unlock_mutex(&phi->arg->m_die), NULL);
	unlock_mutex(&phi->arg->m_die);
	if (phi->arg->num_o_phi == 1)
		return (one_philo(philo), NULL);
	if (phi->id % 2 == 0)
		usleep(100);
	cycle(phi);
	return (NULL);
}
