/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:23:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/04 18:37:35 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main()
{
	Zombie *zomb_list;

	zomb_list = zombieHorde(1000, "Jason");
	for (int i = 0; i < 1000; i++)
		zomb_list[i].announce();
	delete[] zomb_list;
	return 0;
}