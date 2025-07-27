/*Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/
#include <stdio.h>

void	ft_swap(int	*a, int *b)
{
	int	tempA;
	int	tempB;

	tempA = *a;
	tempB = *b;
	*a = tempB;
	*b = tempA;
}

int	main()
{
	int	a = 10;
	int	b = 20;

	ft_swap(&a, &b);
	printf("%d\n",a); //20
	printf("%d\n",b); //10
}