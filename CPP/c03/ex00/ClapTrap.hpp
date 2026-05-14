#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# define COLOR_DEFAULT "\033[0m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_BLUE "\033[34m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_WHITE "\033[37m"

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
		string get_name(void);

		ClapTrap(void);
		ClapTrap(string _name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);

};


#endif