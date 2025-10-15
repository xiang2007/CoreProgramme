/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/15 16:54:52 by wshou-xi         ###   ########.fr       */
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
		free (phi);
		return (1);
	}
	start_philo(ag, phi);
	free(ag->fork);
	free(ag);
	free(phi);
	return (0);
}