/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:34:53 by selow             #+#    #+#             */
/*   Updated: 2025/09/30 16:47:53 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include <stdbool.h>

# define TRUE 1
# define FALSE 0
# define INDEX 2
# define MAX 3

typedef struct s_node
{
	int				content;
	int				index;
	bool			keep;
	int				pos;
	struct s_node	*target_node;
	bool			above_median;
	int				push_cost;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Push_swap main
void	sort_seg(t_node *a);
void	free_stack(t_node **head);
int		init_stack(t_node **a, int argc, char **argv);

// input parsing
int		*split_atoi(const char *s, char sep, int *out_len);	
int		ft_atoi(const char *n);
void	stack_create_and_push(t_node **stack, int *int_arr, int value);
int		*init_arr_atoi(char **argv, int argc);
t_node	*stack_newnode(int content);
int		stack_addback(t_node **lst, t_node *newnode);

// stack utils
t_node	*copy_stack(t_node *stack);
void	clean_stack(t_node **stack);
int		stack_sizeof(t_node **stack);
int		stack_sorted(t_node *stack);
t_node	*stack_newnode_copy(t_node *src);

// execution
t_node	*quicksort_stack(t_node *stack);
void	index_stack(t_node *reference, t_node *stack);
void	assign_index_sorted(t_node *stack);
int		sa_better(t_node *a, int markup);
int		count_keep(t_node *a);
void	apply_keepflag(t_node **a, t_node **b, int markup);
int		add_keepflag(t_node *a, int markup);

// greater markup
int		max_markup(t_node *a, int flag);
int		add_keepflag_max(t_node *head, t_node *start);
int		find_keep_set_max(t_node *a);
void	add_keepflag_max2(t_node *head, t_node *end, int cur_i);

// sort main
void	refresh_median(t_node **stack);
void	calculate_costs(t_node *a, t_node *b);
void	set_target_b(t_node *a, t_node *b);
void	calculate_costs2(t_node *a, t_node *b);
void	prep_to_push(t_node **a, t_node **b, t_node *cheapest);
void	turk_sort(t_node **a, t_node **b);
t_node	*get_smallest(t_node *stack);
t_node	*get_cheapest(t_node *stack);
t_node	*find_cheapest(t_node *b);
void	min_at_top(t_node *a);

//operations
void	sa(t_node **a, int to_print);
void	pb(t_node **a, t_node **b, int to_print);
void	ra(t_node **a, int to_print);
// testing
void	pa(t_node **a, t_node **b, int to_print);
void	rr(t_node **a, t_node **b, int to_print);
void	rrr(t_node **a, t_node **b, int to_print);
void	rra(t_node **a, int to_print);
void	rrb(t_node **b, int to_print);
void	rb(t_node **b, int to_print);

#endif
