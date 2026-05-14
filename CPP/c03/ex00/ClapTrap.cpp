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
	cout << "Destructor called" << endl;
}

void ClapTrap::attack(const string& target) {
	if (this->energy > 0 && this->hit_point > 0) {
		this->energy--;
		cout << "ClapTrap " << COLOR_GREEN << this->name << " attacks " << target << " causing " << this->attack_dmg << " points of damage!" << COLOR_DEFAULT << '\n';
	}
	else if (this->energy <= 0 && this->hit_point > 0) {
		cout << "ClapTrap " << COLOR_YELLOW << this->name << " tried to attack but ran out of energy" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "ClapTrap " << COLOR_RED << this->name << " is defeated and can't attack anymore" << COLOR_DEFAULT << '\n';
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_point <= 0) {
		cout << "ClapTrap " << this->name << COLOR_RED << this->name << " is defeated" << COLOR_DEFAULT << '\n';
	}
	this->hit_point -= amount;
	if (this->hit_point <= 0) {
		this->hit_point = 0;
		cout << "ClapTrap " << this->name << COLOR_RED << this->name << " got hit by a fatal strike of " << amount << " damage and died" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "ClapTrap "<< COLOR_GREEN << this->name << " took " << amount << " of damage. Remaining Hp: " << this->hit_point << COLOR_DEFAULT << '\n';
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_point > 0 && this->energy > 0) {
		cout << "ClapTrap " << COLOR_GREEN << this->name << " repaired " << amount << " point of health" << COLOR_DEFAULT << '\n';
		this->hit_point += amount;
		this->energy--;
	}
	else if (this->hit_point > 0 && this->energy <= 0) {
		cout << "ClapTrap " << COLOR_YELLOW << this->name << " tried to repair itself but ran out of energy" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "ClapTrap " << COLOR_RED << this->name << " tried to repair itself but it's defeated" << COLOR_DEFAULT << '\n';
	}
}

string ClapTrap::get_name() {
	return this->name;
}