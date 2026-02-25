#include "Phonebook.hpp"

void	Phonebook::set_contact(Contact contact, int id)
{
	contacts[id] = contact;
}

Contact	Phonebook::get_contact(int id)
{
	return contacts[id];
}
