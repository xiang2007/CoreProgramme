#include "push_swap.h"

t_stack *ft_nodenew(int	value, int pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->pos = pos;
	node->next = NULL;
	return (node);
}

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;

}

t_stack *ft_lstlast(t_stack *lst)
{
	if (!lst)
		return ;
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack *current;
	t_stack *next_node;

	if (!lst || !(*lst))
		return (NULL);
	current = lst;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}