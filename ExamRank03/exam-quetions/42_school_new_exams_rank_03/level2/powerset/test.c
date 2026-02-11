#include <stdio.h>
#include <stdlib.h>

int	target;
int	size;
int	*nums;

void	printsol(int *num, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", num[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
}

static void	solve(int i, int depth, int sum, int *set)
{
	if (i == size)
	{
		if (sum == target && (depth || !target))
			printsol(set, depth);
		return;
	}
	solve(i + 1, depth, sum, set);
	set[depth] = nums[i];
	solve(i + 1, depth + 1, sum + nums[i], set);
}

int	main(int ac, char **av)
{
	if (ac < 3)
		return (printf("\n"), 1);
	target = atoi(av[1]);
	size = ac - 2;
	nums = malloc(sizeof(int) * size);
	int *set = calloc(size, sizeof(int));
	for (int i = 0; i < size; i++)
		nums[i] = atoi(av[i + 2]);
	solve(0, 0, 0, set);
	free(nums);
	free(set);
	return 0;
}