/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:36:19 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:36:47 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philos *philo)
{
	t_args	*args;

	args = philo->args;
	if (philo->id % 2 == 0)
	{
		lock(&args->forks[philo->r_fork]);
		print(philo, "has taken a right fork 🍴");
		lock(&args->forks[philo->l_fork]);
		print(philo, "has taken a left fork 🍴");
	}
	else
	{
		lock(&args->forks[philo->l_fork]);
		print(philo, "has taken a left fork 🍴");
		lock(&args->forks[philo->r_fork]);
		print(philo, "has taken a right fork 🍴");
	}
	lock(&args->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	unlock(&args->meal_mutex);
	print(philo, "is eating 🍝");
	ft_usleep(args->t_to_eat);
	unlock(&args->forks[philo->l_fork]);
	unlock(&args->forks[philo->r_fork]);
}

void	sleep_think(t_philos *philo)
{
	print(philo, "is sleeping 💤");
	ft_usleep(philo->args->t_to_sleep);
	print(philo, "is thinking 💡");
	if (philo->args->philos_nb % 2)
		usleep(philo->args->t_to_eat * 0.9 * 1000);
}

void	handle_one_philo(t_philos *philo)
{
	lock(&philo->args->forks[philo->l_fork]);
	print(philo, "has taken a fork 🍴");
	ft_usleep(philo->args->t_to_die);
	print(philo, "died 💀");
	unlock(&philo->args->forks[philo->l_fork]);
	philo->args->is_died = 1;
}

void	philo_life_cycle(t_philos *philo)
{
	t_args	*args;

	args = philo->args;
	while (1)
	{
		lock(&args->death_mutex);
		if (args->stop_threads || args->is_died || args->all_satisfied)
		{
			unlock(&args->death_mutex);
			break ;
		}
		unlock(&args->death_mutex);
		eat(philo);
		lock(&args->meal_mutex);
		if (args->must_eat_count != -1
			&& philo->meals_eaten >= args->must_eat_count)
		{
			philo->finish_meals = 1;
			unlock(&args->meal_mutex);
			break ;
		}
		unlock(&args->meal_mutex);
		sleep_think(philo);
	}
}

void	*routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	lock(&philo->args->death_mutex);
	if (philo->args->stop_threads)
		return (unlock(&philo->args->death_mutex), NULL);
	unlock(&philo->args->death_mutex);
	if (philo->args->philos_nb == 1)
		return (handle_one_philo(philo), NULL);
	if (philo->id % 2 == 0)
		usleep(100);
	philo_life_cycle(philo);
	return (NULL);
}
