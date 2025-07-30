/*Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

int	max(int* tab, unsigned int len)
{
	unsigned int	i;
	int	max;

	i = 0;
	max = 0;
	if (tab[0] == '\0')
		return (0);
	while (i < len)
	{
		if (tab[i] > max - 1)
			max = tab[i];
		i++;
	}
	return (max);
}

#include <stdio.h>
int	main()
{
	int	tab[] = {9,2,5,7,1,3,7,9,3,1,4,7,3,4,8,7,3,5,7,8,2,2,4,6,7,3,2,4,7,8,8,5,3,2,1,4,7,9,2};

	printf("%d\n",max(tab, 39));
}