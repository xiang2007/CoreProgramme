#include "Harl.hpp"

void	Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << endl;
}

void	Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" <<endl;
}

void	Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I've been coming foryears, whereas you started working here just last month." << endl;
}

void	Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

void	Harl::complain(string level)
{
	string sub[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[5])(void);

	ptr[0] = &Harl::debug;
	ptr[1] = &Harl::info;
	ptr[2] = &Harl::warning;
	ptr[3] = &Harl::error;
	ptr[4] = NULL;
	for (int i = 0; i < 4; i++) {
		if (level == sub[i]) {
			(this->*ptr[i])();
			return ;
		}
	}
	cout << "Harl is speechless" << endl;
}