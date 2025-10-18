/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:13:51 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/18 15:09:53 by wshou-xi         ###   ########.fr       */
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
		if (pthread_create(&philo[i].thread_id, NULL, p_routine,
			&philo[i]) != 0)
				return (1);
		i++;
	}
	i = 0;
	while (i < ag->num_o_phi)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	return (0);
}
