#include <iostream>
#include <string>
#include <cstring>

int	main(int ac, char **av)
{
	std::string res;

	if (ac == 1)
		return (std::cout << "* LOUD AND UNREADABLE FEEDBACK NOISE *\n", 0);
	else {
		for (int i=1; i<ac; i++)
		{
			for (int j=0; j<(int)strlen(av[i]); j++){
				res += toupper(av[i][j]);
			}
		}
	}
	std::cout << res + '\n';
}
