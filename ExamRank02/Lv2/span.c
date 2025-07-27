/*Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <stddef.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s || !reject)
		return (0);
	while (s[i])
	{
		while (reject[j])
		{
			while (reject[j] != s[i])
				i++;
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main() {
    const char *s = "token1 token2";
    const char *reject = " ";

    size_t len = ft_strcspn(s, reject);
    printf("First space at index: %zu\n", len);  // Output: 6
}