/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:22:58 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/04/07 14:34:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

#define string std::string
#define sin std::cin
#define sout std::cout

class Zombie {
	private:
		string name;
	public:
		Zombie(string name);
		~Zombie();

		void	announce(void) const {
			sout << name << ":\t" << "BraiiiiiiinnnzzzZ..." << std::endl;
		}
		void	set_name(string str){
			name = str;
		}
};

#endif