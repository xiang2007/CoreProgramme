#include "ScavTrap.hpp"

int main() {
	ScavTrap	trap("John");

	trap.guardGate();
	trap.attack("Ball");
	trap.takeDamage(100);
	trap.beRepaired(200);
	return (0);
}