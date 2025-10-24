#include <stdio.h>

int	main()
{
	int	n;
	int	h;
	int	index = 1;
	int	width = 0;
	int	ppl = 0;

	scanf("%d%d",&n,&h);
	while (index <= n)
	{
		scanf("%d",&ppl);
		if (ppl <= h)
			width++;
		else if (ppl > h)
			width = width + 2;
		index++;
	}
	printf("%d\n",width);
}