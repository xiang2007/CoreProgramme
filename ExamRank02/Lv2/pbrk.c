/*Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;
	char *re = (char *)s1;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j])
		{
			j = 0;
			if (s1[i] == s2[j])
				return re;
			j++;
		}
		i++;
		re++;
	}
	return (NULL);
}