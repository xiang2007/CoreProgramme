/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:36:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/15 17:45:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	p_print(char flag, t_philo *phi, t_args *ag)
{
	if (flag == 'f')
	{
		lock_mutex(&ag->print);
		printf("[%lld]\t", (gettime() - ag->start_time));
		printf("Philo %d pick up a fork\n", phi->id);
		unlock_mutex(&ag->print);
	}
	if (flag == 'e')
	{
		lock_mutex(&ag->print);
		printf("[%lld]\t", (gettime() - ag->start_time));
		printf("Philo %d is eating\n", phi->id);
		unlock_mutex(&ag->print);
	}
	if (flag == 't')
	{
		lock_mutex(&ag->print);
		printf("[%lld]\t", (gettime() - ag->start_time));
		printf("Philos %d is thinking\n", phi->id);
		unlock_mutex(&ag->print);
	}
}

void	p_eat(t_args *ag, t_philo *phi)
{
	if (phi->id % 2 == 0)
	{
		lock_mutex(&ag->fork[phi->id - 1]);
		p_print('f', phi, ag);
		lock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
		p_print('f', phi, ag);
	}
	else
	{
		lock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
		p_print('f', phi, ag);
		lock_mutex(&ag->fork[phi->id - 1]);
		p_print('f', phi, ag);
	}
	phi->last_eaten = gettime();
	p_print('e', phi, ag);
	usleep(ag->eat_time * 1000);
	phi->meals_eaten++;
	unlock_mutex(&ag->fork[phi->id - 1]);
	unlock_mutex(&ag->fork[phi->id % ag->num_o_phi]);
}

void	p_sleep(t_args *ag, t_philo *phi)
{
	lock_mutex(&ag->print);
	printf("[%lld]\t", (gettime() - ag->start_time));
	printf("Philo %d is sleeping\n", phi->id);
	unlock_mutex(&ag->print);
	usleep(ag->sleep_time * 1000);
	phi->last_sleep = gettime();
}

void	 p_routine(t_args *ag, t_philo *phi)
{
	if (ag->num_o_phi == 1)
	{
		p_print('f', phi, ag);
		usleep(ag->die_time * 1000);
		ag->stop = 1;
		return ;
	}
	while (1)
	{
		if (ag->stop == 1)
			break ; 
		p_eat(ag, phi);
		if (ag->stop == 1)
			break ;
		p_sleep(ag, phi);
		if (ag->stop == 1)
			break ;
		p_print('t', phi, ag);
		usleep(1000);
	}
	return ;
}
