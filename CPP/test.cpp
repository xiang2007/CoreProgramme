#include "test.hpp"
#include <cmath>

Test::Test(int _a, int _b)
{
	std::cout << "Constructor called" << std::endl;
	a = new int(_a);
	b = new int(_b);
}

Test::Test(const Test& other)
{
	std::cout << "Copy constructor called" << std::endl;
	a = new int(*other.a);
	b = new int(*other.b);
}

Test& Test::operator=(const Test &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		delete a;
		delete b;
		a = new int(*other.a);
		b = new int(*other.b);
	}
	return *this;
}

Test::~Test()
{
	std::cout << "destructor called" << std::endl;
	delete a;
	delete b;
}

void Test::show() const{
	std::cout << "a is :" << *a << std::endl;
	std::cout << "b is :" << *b << std::endl;
}

// int	main()
// {
// 	Test a(10, 20);
// 	Test b = a; // Copy constructor
// 	Test c(200 , 200);
// 	c = a; // Copy asignment

// 	a.show();
// 	b.show();
// 	c.show();
// 	return (0);
// }

using namespace std;

int	main()
{
	float a = 2.1;
	float c;
	int	temp;

	temp = (int)(a * (1 << 8));
	cout << temp << endl;
	c = (float)((float)temp / (1 << 8));
	cout << c << endl;
}