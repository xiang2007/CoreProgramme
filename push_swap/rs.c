/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:52 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 22:03:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_pos(int *arr, int size, t_stack **stack);

int	find_index(int *arr, int index, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == index)
			return (i);
		i++;
	}
	return (-1);
}

void	asign_array(t_stack **stack)
{
	int		i;
	int		size;
	int		*arr;
	t_stack	*temp;

	i = 0;
	size = stacksize((*stack));
	arr = (int *)malloc(sizeof(int) * size);
	temp = (*stack);
	while (i < size)
	{
		arr[i] = temp->value;
		i++;
		temp = temp->next;
	}
	give_pos(arr, size, stack);
	return ;
}

void	give_pos(int *arr, int size, t_stack **stack)
{
	int		i;
	int		index;
	t_stack	*temp;

	i = 0;
	sort(arr, 0, size - 1);
	temp = (*stack);
	while (i < size)
	{
		index = find_index(arr, temp->value, size);
		temp->pos = index;
		i++;
		temp = temp->next;
	}
	free(arr);
}

int	maxbit(t_stack *stack)
{
	int	mbit;
	int	max;

	mbit = 0;
	max = 0;
	while (stack)
	{
		if (stack->pos > max)
			max = stack->pos;
		stack = stack->next;
	}
	while ((max >> mbit) != 0)
		mbit++;
	return (mbit);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	mbit;
	int	size;

	size = stacksize(*a);
	mbit = maxbit(*a);
	i = 0;
	while (i < mbit)
	{
		j = 0;
		while (j < size)
		{
			if (is_stacksort(*a))
				pa(a, b);
			else if ((((*a)->pos >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
