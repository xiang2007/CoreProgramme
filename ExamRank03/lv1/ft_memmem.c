#include "header.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

typedef struct s_data
{
	int	start;
	int	end;
}				t_data;

void	*ft_strstr(char *src, char *to_src, t_data *data)
{
	int	len, len2;
	int i  = 0;
	int	j = 0;
	int	start = 0;

	len = strlen(to_src);
	len2 = strlen(src);
	if (!src || !to_src)
		return (NULL);
	while (j < len)
	{
		if (i >= len2)
			return (NULL);
		if (src[i] != to_src[j])
			i++;
		else if ((src[i] != to_src[j]) && j > 0)
		{
			printf("yes\n");
			start++;
			i = start;
			j = 0;
		}
		if (src[i] == to_src[j])
		{
			i++;
			j++;
		}
	}
	data->end = i - 1;
	data->start = i - j;
	return (NULL);
}


int	main()
{
	t_data	data;
	char	s1[] = "abcdefaaaabcdeabcabcdabc";
	char	s2[] = "abc";
	while (memmem(s1, strlen(s1), s2, strlen(s2)))
	{
		ft_strstr(s1, s2, &data);
		memmove(s1 + data.start + 1, s1 + data.end + 1, strlen(s1 + data.start + 1) + 1);
		s1[data.start] = '*';
	}
	printf("Result is: %s\n", s1);
	return (0);
}
