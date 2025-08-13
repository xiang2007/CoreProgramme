#include <stdlib.h> // for malloc and NULL
#include <stddef.h>
#include <unistd.h> //for write
#include <stdio.h> //for debugging

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
int		is_sorted(char **str);
int		is_stacksort(t_stack *stack);
int		stacksize(t_stack *stack);
t_stack	*asign_stack(int len, char **str);
void	sort_three(t_stack **stack);
void	asign_pos(t_stack *stack);
void	ft_putstr(char *str);
int		find_highest_value(t_stack *stack);
void	print_stack(t_stack **stack);
void	save_three(t_stack **stack_a, t_stack **stack_b);
int		is_stack_reversed(t_stack *stack);
void	update_pos(t_stack *stack);
void	print_pos(t_stack *stack);
int		find_min_pos(t_stack *stack);
void	find_and_push(int pos, t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_b, t_stack **stack_a);
#endif