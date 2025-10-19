/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:13:51 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/19 12:24:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos(t_philo *philo)
{
	t_args	*ag;
	int		i;

	i = 0;
	ag = philo->arg;
	ag->start_time = gettime();
	while (i < ag->num_o_phi)
	{
		philo[i].last_eaten = ag->start_time;
		if (pthread_create(&philo[i].thread_id, NULL, p_routine,
			&philo[i]) != 0)
				return (1);
		i++;
	}
	return (0);
}
