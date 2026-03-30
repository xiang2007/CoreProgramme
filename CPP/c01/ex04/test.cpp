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
	string sub = av[2];
	string trp = av[3];

	if (ac != 4)
		return (1);
	fstream file_in;
	file_in.open("test", ios::in);
	string s;
	while (file_in.is_open()) {
		string line;
		while (getline(file_in, line)) {
			s += line + "\n";
		}
		file_in.close();
	}
	size_t res = -1;
	int	size = sub.size();
	while ((res = s.find(sub, res + 1)) != string::npos) {
		s.erase(s.begin() + res, s.begin() + res + size);
		s.insert(res, trp.c_str());
	}
	s.erase(s.size() - 1);
	string out = av[1];
	string outres = out + ".replace";
	ofstream outfile(outres.c_str());
	outfile << s;
	outfile.close();
	return 0;
}