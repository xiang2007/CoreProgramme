#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		string name;
		Weapon *weapon;

	public:
		HumanB(const string &_name);
		~HumanB();

		void	setWeapon(Weapon &w);
		void	attack(void);
};

#endif