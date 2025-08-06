#include "push_swap.h"

t_stack	*asign_node(int len, char **str)
{
	int	i;
	long int	temp;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	if (!str || len <= 1)
		return (NULL);
	if (!isvalid(str))
		return (NULL);
	while (i < len)
	{
		if (*str[i] == 32)
			i++;
		temp = ft_atoi(str[i]);
		if (stack == NULL)
			stack = ft_nodenew(temp, i);
		else
			ft_lstadd_back(&stack, ft_nodenew(temp, i));
		i++;
	}
	return stack;
}
