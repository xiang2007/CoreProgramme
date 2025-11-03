/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:07:29 by wee               #+#    #+#             */
/*   Updated: 2025/11/03 14:34:11 by wee              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 1;
	char	r1;
	char	r2;
	int	res = 0;
	int	size;

	if (ac > 1)
	{
		size = strlen(av[1]);
		while (j <= size)
		{
			r1 = av[1][i];
			r2 = av[1][j];
			if (r1 == 'x' && r2 == 'x')
				res += 0;
			else if ((r1 == 'x' || r2 == 'x' ) && (r1 == 'A' || r2 == 'A'))
				res += 0;
			else if (r1 == 'x' || r2 == 'x')
				res += (_val(r1) + _val(r2));
			else
				res += (_val(r1) + _val(r2)) + 2;
			printf("i is: %c", r1);
			printf("%c = %d\n", r2, res);
			i += 2;
			j += 2;
		}
		printf("\n%d\n", res);
	}
}