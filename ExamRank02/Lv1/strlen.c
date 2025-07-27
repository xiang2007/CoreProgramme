/*Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main()
{
	char	*str = "HelloWorld"; //should return 10

	printf("%d\n",ft_strlen(str));
	return (0);
}