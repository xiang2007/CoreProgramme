#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	cout << "Default constructor called" << endl;
	name = "None";
	hit_point = 10;
	energy = 10;
	attack_dmg = 10;
}

ClapTrap::ClapTrap(string _name) {
	name = _name;
	hit_point = 10;
	energy = 10;
	attack_dmg = 10;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	cout << "Copy constructor called" << endl;
	name = other.name;
	hit_point = other.hit_point;
	energy = other.energy;
	attack_dmg = other.attack_dmg;
}

ClapTrap  &ClapTrap::operator=(const ClapTrap &other) {
	cout << "Copy assignment operator called" << endl;
	if (this != &other) {
		name = other.name;
		hit_point = other.hit_point;
		energy = other.energy;
		attack_dmg = other.attack_dmg;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	cout << "Destructor called";
}

void ClapTrap::attack(const string& target) {
	cout << this->name << "attacks " << target << " causing " << this->attack_dmg << " points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	cout << this->name << "took " << amount << " damage" << endl;
	this->hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) { 
	cout << this->name << "repaired " << amount << " of health" << endl;
	this->hit_point += amount;
}
