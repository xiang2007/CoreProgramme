#include "Zombie.hpp"

Zombie::Zombie(string _name)
{
	name = _name;
}

Zombie::Zombie(const Zombie &other)
{
	name = other.name;
}

Zombie& Zombie::operator=(const Zombie &other)
{
	if (this != &other)
		name = (other.name);
	return *this;
}

Zombie::~Zombie(){
	sout << "Zombie: " << name << " destroyed\n";
}
