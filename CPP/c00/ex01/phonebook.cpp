#include "Contact.hpp"
#include "Phonebook.hpp"

int	check_input(string buffer)
{
	if (buffer == "ADD" || buffer == "SEARCH" || buffer == "EXIT")
		return 1;
	return 0;
}

int	main()
{
	Phonebook phonebook[7];
	string	buffer;

	sout << "This program only accepts ADD, SEARCH and EXIT" << std::endl;
	while (1)
	{
		sout << "> ";
		sin >> buffer;
		if (check_input(buffer)){
			if (buffer == "EXIT") {
				sout << "Program exited" << std::endl;
				return 0;
			}
			std::cout << "input is: " << buffer << std::endl;
		}
		else {
			sout << "Invalid argument" << std::endl;
			continue ;
		}
	}
}