#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_stack
{
	int	value;
	int	pos;
	struct s_stack *next;
}				t_stack;

int	ft_atoi(const char *str);
