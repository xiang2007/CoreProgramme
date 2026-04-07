#include <bits/stdc++.h>
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

int main(int ac, char **av) {
	if (ac != 4)
		return (cout << "invalid arguments\n<filename> <s1> <s2>" << endl, 1);
	string sub = av[2];
	string trp = av[3];
	if (sub.empty() || trp.empty())
		return (cout << "Empty arguments" << endl, 1);
	fstream file_in;
	file_in.open(av[1], ios::in);
	if (!file_in)
		return (cout << "File '" << av[1] << "' not found" << endl, 1);
	if (file_in.peek() == std::ifstream::traits_type::eof())
		return (cout << "'" << av[1] << "' is a empty file" << endl, 1);
	string s;
	while (file_in.is_open()) {
		string line;
		while (getline(file_in, line)) {
			s += line + "\n";
		}
		file_in.close();
	}
	size_t res = -1;
	int s_size = trp.size();
	int	size = sub.size();
	while ((res = s.find(sub, res + 1)) != string::npos) {
		s.erase(s.begin() + res, s.begin() + res + size);
		s.insert(res, trp.c_str());
		res += s_size - 1;
	}
	s.erase(s.size() - 1);
	string out = av[1];
	string outres = out + ".replace";
	ofstream outfile(outres.c_str());
	outfile << s;
	outfile.close();
	return 0;
}
