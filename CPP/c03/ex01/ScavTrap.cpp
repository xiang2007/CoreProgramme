#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	cout << "ScavTrap default constructor called" << endl;
	name = "None";
	hit_point = 100;
	energy = 50;
	attack_dmg = 20;
}

ScavTrap::ScavTrap(string _name) : ClapTrap(_name){
	cout << "Scavtrap " << _name << " created!" << endl;
	name = _name;
	hit_point = 100;
	energy = 50;
	attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	cout << "ScavTrap copy operator called" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other) {
	cout << "ScavTrap Copy assignment called" << endl;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	cout << "ScavTrap Destructor called" << endl;
}

void ScavTrap::guardGate(void) {
	cout << "ScavTrap is now in Gatekeeper mode" << endl;
}

void ScavTrap::attack(const string& target) {
	cout << this->name << " attacks " << target << " causing " << this->attack_dmg << " points of damage!" << endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	cout << this->name << " took " << amount << " damage" << endl;
	this->hit_point -= amount;
}

void ScavTrap::beRepaired(unsigned int amount) {
	cout << this->name << " repaired " << amount << " of health" << endl;
	this->hit_point += amount;
}