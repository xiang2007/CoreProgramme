#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>

class	Test {
	private:
		int	*a;
		int	*b;

	public:
		Test (int _a, int _b);
		Test (const Test &other);
		Test &operator=(const Test &other);
		~Test();

		void	show() const;

};


#endif