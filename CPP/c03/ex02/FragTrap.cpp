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
	if (this->energy > 0 && this->hit_point > 0) {
		this->energy--;
		cout << "FragTrap " << COLOR_GREEN << this->name << " attacks " << target << " causing " << this->attack_dmg << " points of damage!" << COLOR_DEFAULT << '\n';
	}
	else if (this->energy <= 0 && this->hit_point > 0) {
		cout << "FragTrap " << COLOR_YELLOW << this->name << " tried to attack but ran out of energy" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "FragTrap " << COLOR_RED << this->name << " is defeated and can't attack anymore" << COLOR_DEFAULT << '\n';
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->hit_point <= 0) {
		cout << "FragTrap " << this->name << COLOR_RED << this->name << " is defeated" << COLOR_DEFAULT << '\n';
	}
	this->hit_point -= amount;
	if (this->hit_point <= 0) {
		this->hit_point = 0;
		cout << "FragTrap " << COLOR_RED << this->name << " got hit by a fatal strike of " << amount << " damage and died" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "FragTrap "<< COLOR_GREEN << this->name << " took " << amount << " of damage. Remaining Hp: " << this->hit_point << COLOR_DEFAULT << '\n';
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->hit_point > 0 && this->energy > 0) {
		cout << "FragTrap " << COLOR_GREEN << this->name << " repaired " << amount << " point of health" << COLOR_DEFAULT << '\n';
		this->hit_point += amount;
		this->energy--;
	}
	else if (this->hit_point > 0 && this->energy <= 0) {
		cout << "FragTrap " << COLOR_YELLOW << this->name << " tried to repair itself but ran out of energy" << COLOR_DEFAULT << '\n';
	}
	else {
		cout << "FragTrap " << COLOR_RED << this->name << " tried to repair itself but it's defeated" << COLOR_DEFAULT << '\n';
	}
}

void FragTrap::highFiveGuys(void) {
	cout << "FragTrap " << this->name << " says high five!" << endl;
}