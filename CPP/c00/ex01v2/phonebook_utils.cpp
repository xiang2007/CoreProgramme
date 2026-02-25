#include "Contact.hpp"

void	print_nth(string str, int n)
{
	for (int i = 0; i < 9 && i < n; i++)
		std::cout << str[i];
	if (n > 10)
		std::cout << '.';
}
