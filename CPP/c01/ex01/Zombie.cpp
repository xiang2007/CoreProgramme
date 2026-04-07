/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:16 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/04/07 14:40:21 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
	name = _name;
	std::cout << "Zombie constructer called" << std::endl;
}

Zombie::~Zombie()
{
	sout << "Zombie " << name << " destoyed.\n";
}

Zombie::Zombie() {};