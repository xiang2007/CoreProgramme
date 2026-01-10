#include "Contact.hpp"
#include "Phonebook.hpp"

string	read_input(string prompt)
{
	string	buffer;

	sout << prompt;
	sin >> buffer;
	while (buffer.empty()){
		sout << "Invalid input please enter again.";
		sout << prompt << std::endl;
		sin >> buffer;
	}
	return buffer;
}

void	add_contact(Phonebook &pb)
{
	if (!pb.number_of_contacts || pb.number_of_contacts >= 9)
		pb.number_of_contacts = 1;
	pb.contacts[pb.number_of_contacts - 1].index = pb.number_of_contacts;
	pb.contacts[pb.number_of_contacts - 1].first_name = read_input("Enter first name: ");
	pb.contacts[pb.number_of_contacts - 1].last_name = read_input("Enter last name: ");
	pb.contacts[pb.number_of_contacts - 1].nickname = read_input("Enter nickname: ");
	pb.contacts[pb.number_of_contacts - 1].phone_number = read_input("Enter phone number: ");
	pb.contacts[pb.number_of_contacts - 1].darkest_secret = read_input("Enter darkest secret: ");
	sout << "number of contact: " << pb.number_of_contacts << std::endl;
	pb.number_of_contacts++;
	if (pb.max_contact <= 8)
		pb.max_contact++;
}

void	print_nth(string str, int n)
{
	for (int i = 0; i < 9 && i < n; i++)
		sout << str[i];
	if (n > 10)
		sout << '.';
	sout << '|';
}

void	print_contact(Contact contact)
{
	sout << setw(10) << right << "Index" << '|';
	sout << setw(10) << right << "First Name" << '|';
	sout << setw(10) << right << "Last name" << '|'; 
	sout << setw(10) << right << "Nickname" << '\n';
	sout << setw(10) << right << contact.index << '|';
	if (contact.first_name.length() > 10)
		print_nth(contact.first_name, 11);
	else
		sout << setw(10) << right << contact.first_name << '|';
	if (contact.last_name.length() > 10)
		print_nth(contact.last_name, 11);
	else
		sout << setw(10) << right << contact.last_name << '|';
	if (contact.nickname.length() > 10){
		print_nth(contact.nickname, 11);
		sout << '\n';
	}
	else
		sout << setw(10) << right << contact.nickname << std::endl;
}

void	search(Phonebook &pb)
{
	string input;

	sout << "seach for index: ";
	sin >> input;
	int	index = atoi(input.c_str());

	if (pb.max_contact == 0 && index >= 0)
	{
		sout << "Phonebook is empty.\n";
		return ;
	}
	if (index > pb.max_contact || index <= 0)
	{
		sout << "No contact found!! \n";
		return ;
	}
	else
		print_contact(pb.contacts[index - 1]);
}
