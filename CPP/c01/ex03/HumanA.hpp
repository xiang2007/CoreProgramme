#include <Weapon.hpp>

class HumanA {
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanA();
		HumanA(std::string name);
		HumanA(const std::string &other);
		HumanA& operator=(const std::string &other);
		~HumanA();

		void	set_name(std::string _name);
		void	set_weapon(Weapon w);
		void	get_weapon(void);
};