#include <iostream>
using namespace std;

int	&get_max(int &a, int &b)
{
	return (a > b) ? a : b;
}

int	main()
{
	int x = 10, y = 20;
	int	&value = get_max(x, y);
	cout << value << endl;
	value = 30;
	cout << x << " " << y << endl;
}