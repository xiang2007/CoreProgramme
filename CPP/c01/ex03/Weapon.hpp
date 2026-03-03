#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string type;
	
	public:
		Weapon();
		Weapon(std::string type);
		Weapon(const std::string &other);
		Weapon& operator=(const Weapon &other);
		~Weapon();

		std::string	&get_type();
		void	set_type(const std::string);
};

#endif