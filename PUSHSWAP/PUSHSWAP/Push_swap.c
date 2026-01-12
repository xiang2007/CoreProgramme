/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:53:11 by selow             #+#    #+#             */
/*   Updated: 2025/11/05 18:09:03 by selow            ###   ########.fr       */
/*   Updated: 2025/10/07 16:00:46 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	print_stack(t_node *a);

int	main(int argc, char **argv)
{
	t_node	*a;

	a = NULL;
	if (argc == 1)
		return (0);
	if (!(init_stack(&a, argc, argv)))
		return (1);
	if (!stack_sorted(a))
		sort_seg(a);
	clean_stack(&a);
	return (0);
}

int	init_stack(t_node **a, int argc, char **argv)
{
	int	*int_arr;
	int	len;

	if (argc == 2)
		int_arr = split_atoi(argv[1], ' ', &len);
	else
	{
		int_arr = init_arr_atoi(argv, argc);
		len = argc - 1;
	}
	if (!int_arr)
		return (ft_printf_fd(2, "Error\n"), 0);
	stack_create_and_push(a, int_arr, len);
	free(int_arr);
	return (1);
}

void	sort_seg(t_node *a)
{
	t_node	*sorted;
	t_node	*b;

	b = NULL;
	sorted = quicksort_stack(copy_stack(a));
	index_stack(sorted, a);
	clean_stack(&sorted);
	max_markup(a, TRUE);
	apply_keepflag(&a, &b, MAX);
	turk_sort(&a, &b);
}
/*
// void	print_stack(t_node *head)
// {
// 	t_node	*tmp;

// 	if (!head)
// 	{
// 		printf("(bruh its empty)\n");
// 		return ;
// 	}
// 	// while (head->prev)
// 	// 	head = head->prev;
// 	tmp = head;
// 	while (tmp)
// 	{
// 		printf("Value: %d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }
// void	sort_small(t_node **a)
// {
// 	t_node	*b;
// 	t_node	*sorted;

// 	b = NULL;
// 	if (stack_sizeof(a) == 2)
// 		sa(a, TRUE);
// 	sorted = quicksort_stack(copy_stack(*a));
// 	index_stack(sorted, *a);
// 	clean_stack(&sorted);
// 	while (stack_sizeof(a) > 3)
// 	{
// 		min_at_top(*a);
// 		pb(a, &b, TRUE);
// 	}
// 	sort_three(a);
// 	while (b)
// 		pa(a, &b, TRUE);
// }
// void	sort_three(t_node **a)
// {
// 	int	first;
// 	int	second;
// 	int	third;
// 	printf("hello\n");
// 	first = (*a)->content;
// 	second = (*a)->next->content;
// 	third = (*a)->next->next->content;
// 	if (((first > second && first > third) 
// 		&& (third < first && third < second))
// 		|| ((second > first && second > third)
// 		&& (first < second && first < third)))
// 		sa(a, TRUE);
// 	if ((third > first && third > second) 
// 		&& (second < first && second < third))
// 		sa(a, TRUE);
// 	else if ((first > second && first > third) 
// 		&& (second < first && second < third))
// 		ra(a, TRUE);
// 	else if ((second > first && second > third)
// 		&& (third < first && third < second))
// 		rra(a, TRUE);
// }
*/
