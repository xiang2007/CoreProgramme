#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA John("John", club);
		John.attack();
		club.setType("some other type of club");
		John.attack();
	}

	{
		Weapon dagger = Weapon("swift light dagger");
		HumanB Bob("Bob");
		Bob.attack();
		Bob.setWeapon(dagger);
		Bob.attack();
		dagger.setType("some other type of dagger");
		Bob.attack();
	}
	return 0;
}