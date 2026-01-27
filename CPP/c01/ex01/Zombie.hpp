/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:24:22 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/14 12:42:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#define sout std::cout
#define sin std::cin

#include <iostream>

class Zombie{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string _name);
		Zombie(const Zombie &other);
		Zombie& operator=(const Zombie &other);
		~Zombie();

	void	announce(void) const {
		sout << name << ":\t" << "BraiiiiiiinnnzzzZ..." << std::endl;
	}
	void	set_name(std::string _name){
		name = _name;
	}
};

#endif