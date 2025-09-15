#include <iostream>

int	fib(int nbr)
{
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	return fib(nbr - 1) + fib(nbr - 2);
}

int	main()
{
	int	nbr;
	std::cin >> nbr;
	std::cout  <<  fib(nbr) << '\n';
}