/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:47:41 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/16 17:43:23 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*philo_thread(void *arg)
{
	t_philo_data	*data;

	data = (t_philo_data *)arg;
	p_routine(data->ag, data->philo);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo_data	*data;
	int				flag;

	data = (t_philo_data *)arg;
	flag = monitor_thread(data->ag, data->philo);
	if (flag == 1)
	{
		lock_mutex(&data->ag->die);
		data->ag->stop = 1;
		unlock_mutex(&data->ag->die);
	}
	else if (flag == 2)
	{
		lock_mutex(&data->ag->die);
		data->ag->all_satisfied = 1;
		data->ag->stop = 1;
		unlock_mutex(&data->ag->die);
	}
	return (NULL);
}

void	start_philo(t_args *ag, t_philo *philo)
{
	pthread_t		threads[ag->num_o_phi];
	t_philo_data	data[ag->num_o_phi];
	int				i;

	i = 0;
	ag->start_time = gettime();
	while (i < ag->num_o_phi)
	{
		data[i].ag = ag;
		data[i].philo = &philo[i];
		pthread_create(&threads[i], NULL, philo_thread, &data[i]);
		i++;
	}
	pthread_create(&threads[i], NULL, monitor, &data);
	i = 0;
	while (i < ag->num_o_phi)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
