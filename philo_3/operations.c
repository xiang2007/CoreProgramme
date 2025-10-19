/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:43:34 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/19 14:57:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eat(t_philo *phi)
{
	t_args	*ag;

	ag = phi->arg;
	if (phi->id % 2 == 0)
	{
		lock_mutex(&ag->fork[phi->left_fork]);
		print(phi, "Has taken left fork");
		lock_mutex(&ag->fork[phi->right_fork]);
		print(phi, "Has taken right fork");
	}
	else
	{
		lock_mutex(&ag->fork[phi->right_fork]);
		print(phi, "Has taken right fork");
		lock_mutex(&ag->fork[phi->left_fork]);
		print(phi, "Has taken left fork");
	}
	lock_mutex(&ag->m_meal);
	phi->last_eaten = gettime();
	phi->meals_eaten++;
	unlock_mutex(&ag->m_meal);
	print(phi, "is eating");
	usleep(ag->eat_time * 1000);
	unlock_mutex(&ag->fork[phi->left_fork]);
	unlock_mutex(&ag->fork[phi->right_fork]);
}

void	p_sleep_and_think(t_philo *phi)
{
	print(phi, "is sleeping");
	usleep(phi->arg->sleep_time * 1000);
	print(phi, "is thinking");
	usleep(1000);
}

void	life_cycle(t_philo *phi)
{
	t_args *ag;

	ag = phi->arg;
	while (1)
	{
		lock_mutex(&ag->m_meal);
		if (ag->stop || ag->all_satisfied || phi->died)
		{
			unlock_mutex(&ag->m_meal);
			break ;
		}
		unlock_mutex(&ag->m_meal);
		p_eat(phi);
		lock_mutex(&ag->m_meal);
		if ((ag->must_eat != -1) && (phi->meals_eaten >= ag->must_eat))
		{
			phi->finished = 1;
			unlock_mutex(&ag->m_meal);
			break ;
		}
		unlock_mutex(&ag->m_meal);
		p_sleep_and_think(phi);
	}
}

void	single_philo(t_philo *philo)
{
	print(philo, "has taken a fork");
	usleep(philo->arg->die_time * 1000);
	print(philo, "has died");
	lock_mutex(&philo->arg->m_die);
	philo->died = 1;
	philo->arg->stop = 1;
	unlock_mutex(&philo->arg->m_die);
}

void	*p_routine(void *philo)
{
	t_philo *phi;
	t_args	*ag;

	phi = (t_philo *)philo;
	ag = phi->arg;
	lock_mutex(&ag->m_die);
	if (ag->stop)
		return (unlock_mutex(&ag->m_die), NULL);
	unlock_mutex(&ag->m_die);
	if (ag->num_o_phi == 1)
		return (single_philo(phi), NULL);
	if (phi->id % 2 == 0)
		usleep (100);
	life_cycle(phi);
	return (NULL);
}
