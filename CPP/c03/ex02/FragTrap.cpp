#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void) {
	cout << "FragTrap Default constructor called" << endl;
	name = "None";
	hit_point = 100;
	energy = 100;
	attack_dmg = 30;
}

FragTrap::FragTrap(string _name) : ClapTrap(_name) {
	cout << "FragTrap Default constructor called" << endl;
	name = _name;
	hit_point = 100;
	energy = 100;
	attack_dmg = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	cout << "FragTrap Copy operator called" << endl;
}

FragTrap FragTrap::operator=(const FragTrap& other) {
	cout << "FragTrap copy assignment operator called" << endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	cout << "FragTrap Destructor called" << endl;
}

void FragTrap::attack(const string& target) {
	cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_dmg << " of damage" << endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	cout << "FragTrap " << name << " took " << amount << " of damage" << endl; 
}

void FragTrap::beRepaired(unsigned int amount) {
	cout << "FragTrap " << name << " repaired " << amount << " amount of hp" << endl;
}

void FragTrap::highFiveGuys(void) {
	cout << "FragTrap says high five!" << endl;
}