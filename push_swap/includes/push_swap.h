#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FAIL 0
# define PASS 1
# define WHITESPACE	" \t\n\v\f\r"

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
int		isvalid(char **str);
void	put_instruction(char *instruction);

#endif