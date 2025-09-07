#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	int a, b, t, i, j, temp = 0;
	int	*res;

	scanf("%d", &t);
	temp = t;
	res = (int *)malloc(sizeof(int) * t);
	while (temp)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		while ((a % b) != 0)
		{
			a++;
			i++;
		}
		res[j] = i;
		j++;
		temp--;
	}
	/*j = 0;
	while(j < t)
	{
		printf("%d\n", res[j]);
		j++;
	}*/
	return (0);
}