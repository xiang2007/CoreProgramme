#include "ClapTrap.hpp"

int main() {
	ClapTrap	trap("John");

	trap.attack("rat");
	trap.takeDamage(2);
	trap.beRepaired(20);
	return (0);
}