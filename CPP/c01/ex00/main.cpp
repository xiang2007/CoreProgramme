/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:22:39 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/04 18:15:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main()
{
	Zombie	*zombie;
	Zombie	*zomb;

	zombie = new_zombie("Jason");
	zombie->announce();
	randomChump("Nick");
	delete zombie;
	return 0;
}
