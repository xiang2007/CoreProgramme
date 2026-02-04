/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHoard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/04 18:37:49 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, const char *name)
{
	Zombie *zombie_list = new Zombie[n];
	for (int i=0; i<1000; i++)
		zombie_list[i].set_name("Jason");
	return zombie_list;
}
