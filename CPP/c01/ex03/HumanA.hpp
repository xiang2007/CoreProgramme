#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		string name;
		Weapon &weapon;

	public:
		HumanA(string _name, Weapon &_weapon);
		~HumanA();

		void	attack(void);
};

#endif