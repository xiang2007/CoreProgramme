#include "Phonebook.hpp"

string	readline(string msg)
{
	string temp;

	std::cout << msg << std::endl;
	std::cin >> temp;
	return (temp);
}

void	add_contact(Phonebook *pb, int id)
{
	Contact	c;

	if (id == -1)
		return ;
	c.set_first_name(readline("First name: "));
	c.set_last_name(readline("Last name: "));
	c.set_nickname(readline("Nickname: "));
	c.set_phone_number(readline("Phone Number: "));
	c.set_darkest_secret(readline("Darkest secret: "));
	c.set_id(id + 1);
	pb->set_contact(c, id);
	if (pb->max_contact <= 7)
		pb->max_contact++;
}

int	calculate_id(Phonebook pb)
{
	static int i;

	std::cout << pb.max_contact << std::endl;
	if (pb.max_contact <= 7)
	{
		pb.max_contact++;
		return (i++);
	}
	else if (pb.max_contact == 8)
	{
		if (i > 7)
			i = 0;
		return (i++);
	}
	return (-1);
}

void	search_contact(Phonebook *pb)
{
	int	index;

	if (!pb)
		return ;
	std::cout << "Enter index: " << std::endl;
	std::cin >> index;
	if (index > pb->max_contact) {
		std::cout << "Invalid index (range from 1-" << pb->max_contact << ")" << std::endl;
		return ;
	}
	else
		pb->get_contact(index - 1).print_contact();
	return ;
}

int	main()
{
	Phonebook	phonebook;
	string		line;

	while (1)
	{
		std::cout << "->";
		std::cin >> line;
		if (line == "ADD")
			add_contact(&phonebook, calculate_id(phonebook));
		else if (line == "SEARCH")
			search_contact(&phonebook);
		else if (line == "EXIT")
			return (0);
		else
			std::cout << "Invalid command" << std::endl;
	}
}