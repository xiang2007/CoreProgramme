#include <iostream>
using namespace std;

class Box{
	private:
		int	*value;
	
	public:
		Box (int value); // Constructor
		Box (const Box &other); // Copy constructor
		Box &operator=(const Box &other); // Copy asignment operator
		~Box(); // Destructor

		void	show() const;
};

Box::Box(int _value)
{
	cout << "construtor called" << endl;
	value = new int(_value);
}

Box::Box(const Box &other)
{
	cout << "copy constrctor called" << endl;
	value = new int(*other.value);
}

Box& Box::operator=(const Box &other)
{
	cout << "Copy assignment called" << endl;
	if (this != &other)
	{
		delete value;
		new int (*other.value);
	}
	return *this;
}

Box::~Box()
{
	cout << "destructor called" << endl;
	delete value;
}

void	Box::show() const{
	cout << "Value is: " << *value << endl;
}
