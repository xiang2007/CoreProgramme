#include "FragTrap.hpp"

int main() {
	FragTrap ft1("John");

	ft1.attack("wood");
	ft1.beRepaired(20);
	ft1.takeDamage(200);
	ft1.highFiveGuys();
	return (0);
}