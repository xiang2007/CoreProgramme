#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct s_stack
{
	int	value;
	int	pos;
	int	cost;
	struct s_stack *next;
}				t_stack;

int		ft_atoi(const char *str);
t_stack	*ft_nodenew(int	value, int pos);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst);

#endif