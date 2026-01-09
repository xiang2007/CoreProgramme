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
	sout << "add contact\n";
	if (!pb.number_of_contacts || pb.number_of_contacts > 8)
		pb.number_of_contacts = 1;
	pb.contacts[pb.number_of_contacts - 1].index = pb.number_of_contacts;
	pb.contacts[pb.number_of_contacts - 1].first_name = read_input("Enter first name: ");
	pb.contacts[pb.number_of_contacts - 1].last_name = read_input("Enter last name: ");
	pb.contacts[pb.number_of_contacts - 1].nickname = read_input("Enter nickname: ");
	pb.contacts[pb.number_of_contacts - 1].phone_number = read_input("Enter phone number: ");
	pb.contacts[pb.number_of_contacts - 1].darkest_secret = read_input("Enter darkest secret: ");
	sout << "number of contact: " << pb.number_of_contacts << std::endl;
	pb.number_of_contacts++;
}