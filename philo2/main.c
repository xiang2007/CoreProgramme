/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/17 13:49:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	main(int ac, char **av)
{
	t_philo *phi;
	t_args	*ag;

	ag = malloc(sizeof(t_args));
	phi = parse(ac, av, ag);
	if (!phi)
	{
		free (ag);
		free (phi);
		return (1);
	}
	if (start_philo(ag, phi) != 0)
		return (cleanup(ag, phi), 1);
	if (start_monitor(phi) != 0)
		return (cleanup(ag, phi), 1);
	cleanup(ag, phi);
	return (0);
}
