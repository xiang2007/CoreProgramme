#include <iostream>
#include <fstream>
#include <iosfwd>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;

int	main(int ac, char **av)
{
	fstream	file_in;
	if (ac != 4)
		return (cout << "Invalid arguments" << endl, 1);
	file_in.open(av[1]);
	if (!file_in)
		return (cout << "Invalid infile" << endl, 1);
	string needle = av[2];
	string haystack = av[3];
	if (needle.empty() || haystack.empty()) {
		return (cout << "Argument is empty" << endl, 1);
	}
	string temp_out_name = av[1];
	string file_out_name = temp_out_name + ".replace";
	fstream outfile(file_out_name);
	
}
