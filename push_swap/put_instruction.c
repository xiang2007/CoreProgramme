#include "push_swap.h"

void	put_instruction(char *instruction)
{
	if (instruction[0] == 's' && instruction[1] == 'a')
		write(1, "sa", 2);
	if (instruction[0] == 's' && instruction[1] == 'b')
		write(1, "sb", 2);
	if (instruction[0] == 's' && instruction[1] == 's')
		write(1, "ss", 2);
	if (instruction[0] == 'p' && instruction[1] == 'a')
		write(1, "pa", 2);
	if (instruction[0] == 'p' && instruction[1] == 'b')
		write(1, "pb", 2);
	if (instruction[0] == 'r' && instruction[1] == 'a')
		write(1, "ra", 2);
	if (instruction[0] == 'r' && instruction[1] == 'b')
		write(1, "rb", 2);
	if (instruction[0] == 'r' && instruction[1] == 'r' && !instruction[2])
		write(1, "rr", 2);
	if (instruction[2] == 'a')
		write(1, "rra", 3);
	else if (instruction[2] == 'b')
		write(1, "rrb", 3);
	else if (instruction[2] == 'r')
		write(1, "rrr", 3);
	write(1, "\n", 1);
}
