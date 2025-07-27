/*Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/

#include <stdio.h> //For testing only

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] && s2[i]))
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s2[i] > s1[i])
		return (-1);
	return (0);
}

int	main()
{
	char	*s1 = {"NIHAO"};
	char	*s2 = {"nIHAO"};

	printf("%d\n",ft_strcmp(s1,s2));
}