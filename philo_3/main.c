/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:53:43 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/18 23:31:43 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *philo;
t_args	*arg;

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (1);
	arg = malloc(sizeof(t_args));
	if (!arg)
		return (1);
	if (initializer(ac, av, arg, &philo) == 1)
		return (cleanup(philo, arg), 1);
	if (start_philos(philo) == 1)
		return (cleanup(philo, arg), 1);
	cleanup(philo, arg);
	return (0);
}
