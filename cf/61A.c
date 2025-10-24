#include <stdio.h>
#include <string.h>

int	main()
{
	unsigned int	n1;
	unsigned int	n2;

	scanf("%d%d",&n1,&n2);
	printf("%u\n",n1 ^ n2);
}