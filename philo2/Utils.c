/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:46:23 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/17 14:43:14 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_isalnum(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

t_2l gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print(t_philo *philo, char *message)
{
	lock_mutex(&philo->arg->m_meal);
	lock_mutex(&philo->arg->m_die);
	if (!philo->arg->stop)
	{
		unlock_mutex(&philo->arg->m_die);
		lock_mutex(&philo->arg->m_print);
		printf("%lld %d %s\n", gettime() - philo->arg->start_time,
			philo->id, message);
		unlock_mutex(&philo->arg->m_print);
	}
	unlock_mutex(&philo->arg->m_meal);
}

void	cleanup(t_args *ag, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ag->num_o_phi)
	{
		pthread_mutex_destroy(&ag->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&ag->m_die);
	pthread_mutex_destroy(&ag->m_meal);
	pthread_mutex_destroy(&ag->m_print);
	free (ag->fork);
	free (ag);
	free (philo);
}
