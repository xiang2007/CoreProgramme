#include <stdio.h>

int	main()
{
	int n;
	int	a = 0;
	int index = 0;
	int vacant = 0;
	int	capacity = 0;

	scanf("%d",&n);
	while (index < n)
	{
		scanf("%d%d",&vacant,&capacity);
		if ((vacant + 2) <= capacity)
			a++;
		index++;
	}
	printf("%d\n",a);
}