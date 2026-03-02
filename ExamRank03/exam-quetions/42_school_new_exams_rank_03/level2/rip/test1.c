#include <unistd.h>
#include <stdio.h>

int	len(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

int	min_to_remove(char *s)
{
	int open = 0, close = 0;
	int i = 0;

	while(s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open)
				open--;
			else
				close++;
		}
		i++;
	}
	return open + close;
}

void	solve(char *s, int i, int n, int to_remove, int removed)
{
	if (i == n)
	{
		if (removed == to_remove && min_to_remove(s) == 0)
			puts(s);
		return ;
	}
	if (removed > to_remove)
		return ;
	if (s[i] == '(' || s[i] == ')')
	{
		char c = s[i];
		s[i] = ' ';
		solve (s, n, i + 1, to_remove, removed + 1);
		s[i] = c;
		solve(s, n, i + 1, to_remove, removed);
	}
	else
		solve(s, n, i + 1, to_remove, removed);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	char	*s = av[1];
	int	to_remove = min_to_remove(s);
	if (to_remove == 0)
		return (puts(s), 0);
	int n = len(s);
	solve(s, n, 0, to_remove, 0);
	return 0;
}