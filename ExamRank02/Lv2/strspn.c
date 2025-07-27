/*Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stdlib.h>
#include <stdio.h> //For testing only

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (accept[j])
		{
			if (s[i] != accept[j])
				return (i);
			j++;
			i++;
		}
		i++;
	}
	return (i);
}

int main() {
    const char *s = "abc123xyz";

    // Accept only letters
    const char *accept = "abcdefghijklmnopqrstuvwxyz";
    // Reject digits
    size_t span_len = ft_strspn(s, accept);     // Stops at '1'

    printf("strspn: %zu\n", span_len);    // Output: 3

    return 0;
}