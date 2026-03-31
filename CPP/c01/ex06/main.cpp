#include "Harl.hpp"

void	print_complains(string str)
{
	int e;
	string sub[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl h;

	for (e = 0; e < 4; e++) {
		if (str == sub[e])
			break;
	}
	switch (e) {
		case 0:
			h.complain("DEBUG");
			break ;
		case 1:
			h.complain("DEBUG");
			h.complain("INFO");
			break ;
		case 2:
			h.complain("DEBUG");
			h.complain("INFO");
			h.complain("WARNING");
			break ;
		case 3:
			h.complain("DEBUG");
			h.complain("INFO");
			h.complain("WARNING");
			h.complain("ERROR");
			break ;
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
	}
}


int	main(int ac, char **av)
{
	string str;

	if (ac != 2)
		return (1);
	str = av[1];
	print_complains(str);
	return 0;
}