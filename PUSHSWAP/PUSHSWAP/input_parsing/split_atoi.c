/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:17:15 by selow             #+#    #+#             */
/*   Updated: 2025/10/29 14:40:52 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
	splits a string of numbers separated by a separator,
	and includes them into an int array. 
	
	Returns NULL if one element contains something that isnt a number.
	ALSO RETURNS NULL IF ONE ELEMENT IS A DUPLICATE.
*/

static int	is_number(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	if (*s < '0' || *s > '9')
		return (0);
	while (*s)
	{
		if (*s == ' ')
			break ;
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

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

static int	*fill_int_arr(const char *s, char sep, int *arr)
{
	const char	*p;
	int			i;

	p = s;
	i = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (!(*p))
			break ;
		if (!(is_number(p)))
			return (free(arr), NULL);
		arr[i++] = ft_atoi(p);
		if (has_duplicate(arr, i, arr[i - 1]))
			return (free(arr), NULL);
		while (*p && *p != sep)
			p++;
	}
	return (arr);
}

int	*split_atoi(const char *s, char sep, int *out_len)
{
	int			count;
	const char	*p;
	int			*arr;

	if (!s || !*s)
		return (NULL);
	count = 0;
	p = s;
	*out_len = 0;
	while (*p)
	{
		while (*p && *p == sep)
			p++;
		if (*p)
		{
			count++;
			while (*p && *p != sep)
				p++;
		}
	}
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	*out_len = count;
	return (fill_int_arr(s, sep, arr));
}

/*
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		return (1);
    int len, i;
    int *nums = split_atoi(argv[1], ' ', &len);

    if (!nums)
        return 1;

    for (i = 0; i < len; i++)
        printf("%d\n", nums[i]);
	if (nums == NULL)
		printf("ERROR\n");

    free(nums);
    return 0;
}*/
