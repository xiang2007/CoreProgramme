#include "push_swap.h"

t_stack	**node_atoi(char **str, int len)
{
	int	i;
	int	temp;
	t_stack *node;
	t_stack *head;

	i = 1;
	head = NULL;
	if (!str || len < 1)
		return ;
	while (i < len)
	{
		temp = ft_atoi(str[i]);
		node = ft_nodenew(temp, i);
		if (!node)
		{
			ft_lstclear(node);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
