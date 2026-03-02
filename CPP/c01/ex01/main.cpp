/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:23:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/03/02 19:56:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main()
{
	Zombie *zomb_list;
	std::string name;

	name = "Jason";
	zomb_list = zombieHorde(10, name);
	for (int i = 0; i < 10; i++)
		zomb_list[i].announce();
	delete[] zomb_list;
	return 0;
}