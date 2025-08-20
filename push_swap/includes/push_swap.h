/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:11 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 18:16:34 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

# define FAIL 0
# define PASS 1

typedef struct s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
}	t_stack;

int		ft_atoi(const char *str);
t_stack	*ft_nodenew(int value, int pos);
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
int		find_highest_pos(t_stack *stack);
void	save_three(t_stack **stack_a, t_stack **stack_b);
int		is_stack_reversed(t_stack *stack);
void	update_pos(t_stack *stack);
int		find_min_pos(t_stack *stack);
void	find_and_push(int pos, t_stack **stack_a, t_stack **stack_b);
void	ft_selection(t_stack **stack_a, t_stack **stack_b);
void	errmsg(t_stack **stack_a, t_stack **stack_b);
int		quicksort(int ac, char **av);
void	sort(int *arr, int first, int last);
void	asign_array(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
int		checkdup(char **str);
int		onlynumbers(char *str);
void	checkone(char *str);
int		ft_isdigit(int c);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

#endif
