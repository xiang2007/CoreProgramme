#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

#define string std::string
#define sin std::cin
#define sout std::cout

class Zombie {
	private:
		string name;
	public:
		Zombie(string name);
		Zombie(const Zombie &other);
		Zombie& operator=(const Zombie& other);
		~Zombie();

		void	announce(void) const {
			sout << name << ":\t" << "BraiiiiiiinnnzzzZ..." << std::endl;
		}
		void	set_name(string str){
			name = str;
		}
};

#endif