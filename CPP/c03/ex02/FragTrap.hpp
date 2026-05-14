#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFiveGuys(void);

		FragTrap(void);
		FragTrap(string _name);
		FragTrap(const FragTrap& other);
		FragTrap operator=(const FragTrap &other);
		~FragTrap(void);
};

#endif