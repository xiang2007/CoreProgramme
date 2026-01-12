/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:16 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/12 20:44:31 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(string _name)
{
	name = _name;
}

Zombie::Zombie(const Zombie &other)
{
	name = other.name;
}

Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other)
		name = other.name;
	return *this;
}

Zombie::~Zombie()
{
	sout << "Zombie " << name << " destoyed.";
}

Zombie::Zombie() {};