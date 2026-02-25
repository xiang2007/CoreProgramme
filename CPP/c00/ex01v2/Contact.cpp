#include "Contact.hpp"

void	Contact::set_first_name(string f_name)
{
	first_name = f_name;
}

void	Contact::set_last_name(string l_name)
{
	last_name = l_name;
}

void	Contact::set_phone_number(string phonenumber)
{
	phone_number = phonenumber;
}

void	Contact::set_nickname(string n_name)
{
	nickname = n_name;
}

void	Contact::set_darkest_secret(string ds)
{
	darkest_secret = ds;
}

void	Contact::set_id(int i)
{
	id = i;
}

void	Contact::print_contact()
{
	std::cout << std::setw(10) << std::right << "Index" << '|';
	std::cout << std::setw(10) << std::right << "First Name" << '|';
	std::cout << std::setw(10) << std::right << "Last name" << '|'; 
	std::cout << std::setw(10) << std::right << "Nickname" << '|' << '\n';
	std::cout << std::setw(10) << std::right << id << '|';
	if (first_name.length() > 10) {
		print_nth(first_name, 11);
		std::cout << "|";
	}
	else
		std::cout << std::setw(10) << std::right << first_name << '|';
	if (last_name.length() > 10) {
		print_nth(last_name, 11);
		std::cout << "|";
	}
	else
		std::cout << std::setw(10) << std::right << last_name << '|';
	if (nickname.length() > 10){
		print_nth(nickname, 11);
		std::cout << '|' << '\n';
	}
	else
		std::cout << std::setw(10) << std::right << nickname << '|' << std::endl;
}
