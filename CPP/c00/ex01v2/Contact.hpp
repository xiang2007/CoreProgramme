#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

#define string std::string

class Contact {
	private:
		int		id;
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	
	public:
		void	set_id(int id);
		void	set_first_name(string f_name);
		void	set_last_name(string l_name);
		void	set_nickname(string n_name);
		void	set_phone_number(string phonenumber);
		void	set_darkest_secret(string ds);
		void	print_contact();

	Contact(): id(1), first_name(""), last_name(""),
		nickname(""), phone_number(""), darkest_secret("") {};
};

void	print_nth(string str, int n);

#endif