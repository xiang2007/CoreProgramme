#include "Zombie.hpp"

Zombie	*new_zombie(string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}