/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:14:19 by selow             #+#    #+#             */
/*   Updated: 2025/08/31 22:14:20 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
	Converts argv into an int array.

	Returns NULL if 
	- one element contains something that isn't a number.
	- one element is a duplicate 
	- one element is bigger than INT_MAX
*/

static int	has_duplicate(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

static int	is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

static int	*fill_int_arr(char **argv, int argc, int *arr)
{
	int	i;
	int	val;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			free(arr);
			return (NULL);
		}
		val = ft_atoi(argv[i]);
		arr[i - 1] = val;
		if (has_duplicate(arr, i, val))
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

int	*init_arr_atoi(char **argv, int argc)
{
	int	*arr;

	if (argc <= 1)
		return (NULL);
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	return (fill_int_arr(argv, argc, arr));
}
