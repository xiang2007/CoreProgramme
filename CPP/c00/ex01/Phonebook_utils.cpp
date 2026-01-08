#include "Contact.hpp"
#include "Phonebook.hpp"

void	add_contact(Phonebook pb)
{
	int		number_of_contatcts = pb.number_of_contacts;
	if (pb.number_of_contacts == 8){
		//do something
	}
	else
	{
		if (!pb.number_of_contacts)
			pb.number_of_contacts = 1;
		sout << "Enter first name: ";
		sin >> pb.contacts[pb.number_of_contacts - 1].first_name;
		if (!pb.contacts[pb.number_of_contacts - 1].first_name)

		sout << "\nEnter last name: ";
		sin >> pb.contacts[pb.number_of_contacts - 1].last_name;
		sout << "\nEnter nickname: ";
		sin >> pb.contacts[pb.number_of_contacts - 1].nickname;
		sout << "\nEnter Phone number: ";
		sin >> pb.contacts[pb.number_of_contacts - 1].phone_number;
		sout << "\nEnter darkest_secret ";
		sin >> pb.contacts[pb.number_of_contacts - 1].darkest_secret;
	}
}