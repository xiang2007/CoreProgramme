#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char *ft_ltoa(long n);

int	main()
{
	long number;
	char *buffer;
	int	index = 0;

	scanf("%ld",&number);
	buffer = ft_ltoa(number);
	while (buffer[index])
	{
		if ((buffer[index] == '4' || buffer[index] == '7') && buffer[index] == '4')
			index++;
		else
		{
			printf("%s\n","NO");
			return (0);
		}
	}
	printf("%s\n","YES");
}

char *ft_ltoa(long n)
{
	char	*str;
	int		len = 0;
	long	tmp = n;

	// Handle 0 case
	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	// Count digits
	if (n < 0)
		len++;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	// Fill digits from the end
	if (n < 0)
		str[0] = '-';

	tmp = (n < 0) ? -(long)n : n;
	while (tmp)
	{
		str[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}

	return (str);
}
