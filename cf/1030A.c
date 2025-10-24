#include <stdio.h>

int	main()
{
	int	n;
	int	r;
	int	index = 0;

	scanf("%d",&n);
	while (index < n)
	{
		scanf("%d",&r);
		if (r == 1)
		{
			printf("%s\n","HARD");
			return (0);
		}
		else
			index++;
	}
	printf("%s\n","EASY");
	return (0);
}