/*Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

int	main()
{
	char	src[10] = {"NIHAO"};
	char	*dest = malloc(11);

	dest[10] = '\0';
	dest = ft_strcpy(dest, src);
	printf ("%s\n", dest);
	free (dest);
	return (0);
}