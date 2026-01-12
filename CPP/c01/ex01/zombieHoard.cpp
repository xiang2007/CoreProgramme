/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHoard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/12 20:39:04 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, string name)
{
	Zombie *zombie_list = new Zombie[n];
	for (int i = 0; i < n; i++) {
		zombie_list[i] = Zombie(name);
	}
	return zombie_list;
}