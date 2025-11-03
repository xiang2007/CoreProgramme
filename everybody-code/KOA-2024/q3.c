/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:07:29 by wee               #+#    #+#             */
/*   Updated: 2025/11/03 15:15:45 by wee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# define A 0
# define B 1
# define C 3
# define D 5
# define x 0


int	_val(char c)
{
	switch (c)
	{
		case 'A':
			return (A);
		case 'B':
			return (B);
		case 'C':
			return (C);
		case 'D':
			return (D);
		default:
			return (0);
	}
}

int	_count_x(char a, char b, char c)
{
	int	i = 0;

	if (a == 'x')
		i++;
	if (b == 'x')
		i++;
	if (c == 'x')
		i++;
	return (i); 
}

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 1;
	int	k = 2;
	char	r1;
	char	r2;
	char	r3;
	int	res = 0;
	int	size;

	if (ac > 1)
	{
		size = strlen(av[1]);
		while (k <= size)
		{
			r1 = av[1][i];
			r2 = av[1][j];
			r3 = av[1][k];
			if (_count_x(r1, r2, r3) == 3)
				res += 0;
			else if (_count_x(r1, r2, r3) == 2)
				res += (_val(r1) + _val(r2) + _val(r3));
			else if ((r1 == r2 || r1 == r3 || r2 == r3) && _count_x(r1, r2, r3) == 0)
				res += (_val(r1) + _val(r2) + _val(r3)) + 6;
			else if (_count_x(r1, r2, r3) == 1)
				res += (_val(r1) + _val(r2) + _val(r3)) + 2;
			else if (_count_x(r1, r2, r3) == 0)
				res += (_val(r1) + _val(r2) + _val(r3)) + 6;
			else
				res += 0;
			i += 3;
			j += 3;
			k += 3;
		}
		printf("\n%d\n", res);
	}
}
