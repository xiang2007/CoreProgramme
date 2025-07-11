#include <iostream>
#include <cstring>

int		main()
{
	char	c;
	char	*str;
	char	buffer[1024] = {'\0'};
	int	nbr;
	int	index(0);
	int	size(0);

	std::cout << "Number input: ";
	std::cin >> nbr;
	std::cout  <<  nbr <<  '\n';
	std::cout << "Character input: ";
	std::cin >> c;
	std::cout << c << '\n';
	std::cout << "String input: ";
	std::cin  >>  buffer;
	size = strlen(buffer);
	str = (char *)malloc(sizeof(char) * size + 1);
	while (size)
	{
		str[index] = buffer[index];
		size--;
	}
	str[size] = '\0';
	std::cout << buffer << '\n';
	return 0;
}