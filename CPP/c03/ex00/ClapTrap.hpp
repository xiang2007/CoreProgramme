#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

class ClapTrap
{
	private:
		string	name;
		int		hit_point;
		int		energy;
		int		attack_dmg;

	public:
		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		ClapTrap(void);
		ClapTrap(string _name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);
		
};


#endif