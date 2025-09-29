#include "header.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	errmsg(void);

char	*ft_strdup(char *str)
{
	int	i;
	char	*temp;

	i = 0
	if (!str)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * strlen(str));
	if (!temp)
		errmsg();
	while (i < strlen(str))
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*gnl()
{
		char	temp[1];
		read(STDIN, temp, 1);

}

void	errmsg(void)
{
	perror("Error");
	printf("\n");
	exit(1);
}


int	main()
{
	char	s1[] = "abcdefaaaabcdeabcabcdabc";
	char	s2[] = "abc";
	char	*ptr;
	unsigned long	i;

	ptr = memmem(s1, strlen(s1), s2, strlen(s2));
	while (ptr)
	{
		i = 0;
		while (i < strlen(s2))
		{
			*ptr = '*';
			i++;
			ptr++;
		}
		ptr = memmem(ptr, strlen(ptr), s2, strlen(s2));
	}
	printf("Result is: %s\n", s1);
	return (0);
}
