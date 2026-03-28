#include "HumanA.hpp"

HumanA::HumanA(string _name, Weapon &_weapon): weapon(_weapon), name(_name) {}

HumanA::~HumanA()
{
	cout << "Destructor called" << endl;
}

void	HumanA::attack(void)
{
	cout << name << " Attack with " << weapon.getType() << endl;
}