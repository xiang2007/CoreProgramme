/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:49:07 by marvin            #+#    #+#             */
/*   Updated: 2025/08/21 12:37:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
		errmsg(NULL, NULL);
	return (result * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}

int	stacksize(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (!stack)
		errmsg(&stack, NULL);
	temp = stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	asign_pos(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		errmsg(&stack, NULL);
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
	return ;
}

int	find_highest_pos(t_stack *stack)
{
	int	max;
	int	pos;

	if (!stack)
		return (0);
	max = stack->value;
	pos = stack->pos;
	while (stack)
	{
		if ((stack->value) > max)
		{
			max = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}
