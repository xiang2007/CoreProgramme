#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	Phonebook{
	public:
		Contact	contacts[8];
		int		number_of_contacts;
		int		max_contact;

	Phonebook() : number_of_contacts(0), max_contact(0) {}
};

void	add_contact(Phonebook &pb);
void	search(Phonebook &pb);

#endif