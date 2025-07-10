#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*appendline(char *str, char **remain)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	size = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*remain = (char *)malloc(size - i);
		if (!*remain)
			return (NULL);
		i++;
		while (str[i])
			(*remain)[j++] = str[i++];
		(*remain)[j] = '\0';
		str[i - j - 1] = '\0';
	}
	else
		*remain = NULL;
	return (str);
}

int	main()
{
	char	*str = "hello\nworld";
	char	*remainder;

	appendline(str, &remainder);
	printf("%s\n",str);
	printf("%s\n",remainder);
	free(remainder);
	return (0);
}