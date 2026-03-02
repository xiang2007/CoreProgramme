#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

#define string std::string

class Weapon{
	private:
		string type;
	
	public:
		Weapon();
		Weapon(string type);
		Weapon(const string &other);
		Weapon& operator=(const Weapon &other);
		~Weapon();

		string	&get_type();
		void	set_type(const string);
};

#endif