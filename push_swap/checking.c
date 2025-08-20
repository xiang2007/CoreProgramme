/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:21 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 13:17:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stacksort(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	onlynumbers(char *av)
{
	int	i;

	i = 0;
	if (!*av)
		return (FAIL);
	if ((av[i] == '+' || av[i] == '-') && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (FAIL);
	return (PASS);
}

int	checkdup(char **str)
{
	int		i;
	int		j;
	long	nbr1;
	long	nbr2;

	i = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		j = 1;
		nbr1 = ft_atoi(str[i]);
		while (str[j + i])
		{
			nbr2 = ft_atoi(str[j + i]);
			if (nbr1 == nbr2)
				return (FAIL);
			j++;
		}
		i++;
	}
	return (PASS);
}

int	is_sorted(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 1;
	while (str[i + 1])
	{
		if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
			return (PASS);
		i++;
	}
	return (FAIL);
}

int	isvalid(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!onlynumbers(str[i]))
			errmsg(NULL, NULL);
		i++;
	}
	if (!checkdup(str))
		errmsg(NULL, NULL);
	return (PASS);
}
