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
	Phonebook phonebook;
	string	buffer;

	sout << "This program only accepts ADD, SEARCH and EXIT" << std::endl;
	while (1)
	{
		sout << "> ";
		getline(sin >> std::ws, buffer, '\n');
		if (check_input(buffer)){
			if (buffer == "EXIT") {
				sout << "Program exited" << std::endl;
				return 0;
			}
			else if (buffer == "ADD")
				add_contact(phonebook);
			else if (buffer == "SEARCH")
				search(phonebook);
		}
		else {
			sout << "Invalid argument" << std::endl;
			continue ;
		}
	}
}