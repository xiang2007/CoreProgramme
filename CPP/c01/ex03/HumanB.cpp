#include "HumanB.hpp"

HumanB::HumanB(const string &_name): name(_name), weapon(NULL) {}

HumanB::~HumanB()
{
	cout << "Destructor called" << endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	weapon = &w;
}

void	HumanB::attack(void)
{
	if (weapon == NULL)
		cout << name << " Failed to attack" << endl;
	else
		cout << name << " attack with " << weapon->getType() << endl;
}
