/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:54:32 by wee               #+#    #+#             */
/*   Updated: 2025/11/03 14:02:27 by wee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int main(int ac, char **av)
{
	int i = 0;
	int res = 0;

	if (ac > 1)
	{
		while (av[1][i])
		{
			switch (av[1][i])
			{
				case 'A':
					res += 0;
					break ;
				case 'B':
					res += 1;
					break ;
				case 'C':
					res += 3;
					break ;
				default:
					break ;
			}
			i++;
		}
	}
	printf("%d\n", res);
}