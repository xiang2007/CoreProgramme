#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	Phonebook{
	private:
		Contact contacts[8];
	public:
		int		max_contact;
		void	set_contact(Contact c, int id);
		Contact	get_contact(int id);
	
	Phonebook(): max_contact(0) {}
};

#endif