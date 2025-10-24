#include <stdlib.h>
#include <stdio.h>

void	changechar(char *str, int sign);

int	main()
{
	char *words;
	int	index = 0;
	int	low = 0;
	int	up = 0;

	words = calloc(100, sizeof(char));
	scanf("%s",words);
	while (words[index])
	{
		if (words[index] >= 65 && words[index] <= 90)
		{
			up++;
			index++;
		}
		else if (words[index] >= 97 && words[index] <= 122)
		{
			low++;
			index++;
		}
	}
	if (up > low)
		changechar(words, 1);
	if (up < low)
		changechar(words, 2);
	if (up == low)
		changechar(words, 2);
	return(0);
}

void	changechar(char *str, int sign)
{
	int	i = 0;

	while (str[i])
	{
	if (sign == 1)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}
	else if (sign == 2)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	}
	printf("%s\n",str);
}