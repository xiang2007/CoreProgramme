/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wee <wee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:18:56 by wee               #+#    #+#             */
/*   Updated: 2025/11/03 16:10:59 by wee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int	main(int ac, char **av)
{
	int	res = 0;
	char	words[] = "LOR,LL,SI,OR,RE,EP,OL";
	const char	*tok;
	
	if (ac < 2)
		return (0);
	tok = strtok(words, ",");
	(void)av;
	while (tok != NULL)
	{
		while (strstr(av[1], tok) != NULL)
			res++;
		printf("tok is: %s\n", tok);
		tok = strtok(NULL, ",");
	}
	printf("%d\n", res);
}