/*

I have 2 stacks named a and b
Stack a contains random positive / negative number
Stack b is empty
Goal is to sort stack a

-----------------------------------------------------------

Commands:
sa (swap a):
stack a			stack a
2		--->	1
1				2

sb (swap b):
stack b			stack b
2		--->	1
1				2

ss (swap a and swap b)
stack a		stack b					stack a		stack b
2			1			--->		1			2
1			2						2			1

pa (push a) Do nothing if stack b is empty
stack a		stack b					stack a		stack b
2			1			--->		1			
3									2
`									3

pb (push b) Do nothing if stack a is empty
stack a		stack b					stack a		stack b
2			1			--->		3			2
3												1

ra (rotate stack a): shift all element ar stack a by 1
stack a			stack a
3				1
1		--->	2
2				3

rb (rotate b): shift all element ar stack b by 1
stack b			stack b
3				1
1		--->	2
2				3

rr (rotate stack a and stack b)
stack a		stack b					stack a		stack b
2			1			--->		1			2
1			2						2			1











*/


#include "push_swap.h"

