#include <iostream>
#include <fstream>
#include <iosfwd>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::string;
using std::fstream;
using std::ofstream;
using std::ios;

int	main(int ac, char **av)
{
	fstream	file_in;
	if (ac != 4)
		return (cout << "Invalid arguments, <filename> <s1> <s2>" << endl, 1);
	file_in.open(av[1], ios::in);
	if (!file_in)
		return (cout << "Invalid infile" << endl, 1);
	string sub = av[2];
	string to_replace = av[3];
	if (sub.empty() || to_replace.empty()) {
		return (cout << "Argument is empty" << endl, 1);
	}
	string temp_out_name = av[1];
	string file_out_name = temp_out_name + ".replace";
	ofstream outfile(file_out_name.c_str());
	outfile.open(file_out_name.c_str(), ios::out);
	string buffer;
	while (file_in.is_open()) {
		string line;
		while (getline(file_in, line)) {
			buffer += line + '\n';
		}
		file_in.close();
	}
	// size_t res = -1;
	cout << buffer;
	// while ((res = buffer.find(sub, res + 1) != string::npos)) {
	// 	buffer.erase(buffer.begin() + res);
	// 	// buffer.insert(res, to_replace);
	// 	cout << res << " ";
	// }
	// cout << buffer << endl;
}
