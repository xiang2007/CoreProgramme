#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#define sout std::cout
#define sin std::cin
#define string std::string
#define setw std::setw
#define right std::right

class Contact{
	public:
		int	index;
		string first_name;
		string last_name;
		string nickname;
		string phone_number;
		string darkest_secret;

	Contact(): index(1), first_name(""), last_name(""),
		nickname(""), phone_number(""), darkest_secret("") {}

	Contact(int index, string f_name, string l_name, string n_name,
			string p_number, string d_secret)
			: index(index), first_name(f_name), last_name(l_name), nickname(n_name),
				phone_number(p_number), darkest_secret(d_secret) {} 
};

#endif
