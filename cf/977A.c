#include <stdio.h>

int	main()
{
	int	number;
	int	times;

	scanf("%d %d",&number, &times);
	while (times > 0)
	{
		if (number % 10 != 0)
			number -= 1;
		else if (number % 10 == 0)
			number /= 10;
		times--;
	}
	printf("%d\n",number);
}