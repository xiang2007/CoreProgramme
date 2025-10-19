/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:11:17 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/19 16:20:21 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf("Error locking mutex\n");
		return ;
	}
}

void	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf("Error unlocking mutex\n");
		return ;
	}
}

void	destroy_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
	{
		printf("Error destroying mutex\n");
		return ;
	}
}

void	cleanup(t_philo *philo, t_args *ag)
{
	int	i;

	i = 0;
	if (!philo || !ag)
		return ;
	while (i < ag->num_o_phi)
	{
		destroy_mutex(&ag->fork[i]);
		i++;
	}
	destroy_mutex(&ag->m_die);
	destroy_mutex(&ag->m_meal);
	destroy_mutex(&ag->m_print);
	free(ag->fork);
	free(ag);
	free(philo);
}
