#include <stdio.h>

int	main()
{
	int	banana;
	int	money;
	int	price;
	int	mult = 1;
	int	total = 0;

	scanf("%d %d %d",&price, &money, &banana);
	while (banana)
	{
		total += (price * mult);
		mult++;
		banana--;
	}
	if (money > total)
	{
		printf("%d\n",0);
		return (0);
	}
	printf("%d\n",(total - money));
	return (0);
}