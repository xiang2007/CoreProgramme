/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:38:55 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/16 20:55:06 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	philo_die(t_philo *phi, t_args *ag)
{
	int	i;

	i = 0;
	lock_mutex(&ag->monitor);
	if (ag->stop)
	{
		lock_mutex(&phi[i].time);
		if (ag->all_satisfied)
		{
			printf("All philo satisfied!!\n");
			unlock_mutex(&phi[i].time);
			return (1);
		}
		while(i < ag->num_o_phi)
		{
			if (phi[i].died == 1)
			{
				printf("[%lld]\tPhilo %d has died\n", phi->die_time, phi->id);
				unlock_mutex(&phi[i].time);
			}
			i++;
		}
		unlock_mutex(&ag->monitor);
	}
	return (0);
}
