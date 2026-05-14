#include "ClapTrap.hpp"

int main() {
	ClapTrap	t1("t1");
	ClapTrap	t2("t2");

	t1.attack(t2.get_name());
	t2.takeDamage(5);
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.takeDamage(6);
	t1.beRepaired(3);
	
	t1.attack(t2.get_name());
	t2.takeDamage(1);
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.takeDamage(1);
	t1.beRepaired(2);

	t1.attack(t2.get_name());
	t2.takeDamage(1);
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.takeDamage(1);
	t1.beRepaired(2);

	t1.attack(t2.get_name());
	t2.takeDamage(1);
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.takeDamage(1);
	t1.beRepaired(2);

	t1.attack(t2.get_name());
	t2.takeDamage(1);
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.beRepaired(2);

	t1.attack(t2.get_name());
	t2.beRepaired(2);

	t2.attack(t1.get_name());
	t1.beRepaired(2);
	return (0);
}