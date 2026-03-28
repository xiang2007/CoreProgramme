#include "Weapon.hpp"

const string& Weapon::getType(void) const {
	return (type);
}

Weapon::Weapon(const string& name) {
	type = name;
}

void	Weapon::setType(const string &Type) {
	type = Type;
}

Weapon::~Weapon()
{
	cout << "Weapon Destructor called" << endl;
}