#include <stdio.h>

int	main()
{
	int	n;
	int sign = 0;

	scanf("%d",&n);
	while (n)
	{
		if (sign == 0 && n == 1)
		{
			printf("%s", "I hate it");
			break;
		}
		else if (sign == 1 && n == 1)
		{
			printf("%s", " I love it");
			break;
		}
		else if (sign == 0)
		{
			printf("%s", "I hate that");
			sign = 1;
		}
		else if (sign == 1)
		{
			printf("%s", " I love that ");
			sign = 0;
		}
		n--;
	}
	printf("\n");
}