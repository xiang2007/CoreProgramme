/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHoard.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:25 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/14 13:16:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, const char *name)
{
	Zombie *zombie_list = new Zombie[n];
	(*zombie_list).set_name(name);
	return zombie_list;
}
