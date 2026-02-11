#include <stdio.h>
#include <stdlib.h>

int	g_target;
int	g_size;
int	*g_nums;

static void	solve(int idx, int depth, int sum, int *set)
{
    if (idx == g_size)
    {
        if (sum == g_target && (depth || !g_target))
        {
            for (int i = 0; i < depth; i++)
                printf(i ? " %d" : "%d", set[i]);
            printf("\n");
        }
        return;
    }
    solve(idx + 1, depth, sum, set);
    set[depth] = g_nums[idx];
    solve(idx + 1, depth + 1, sum + g_nums[idx], set);
}

int	main(int ac, char **av)
{
    if (ac < 3)
        return (printf("\n"), 1);
    g_target = atoi(av[1]);
    g_size = ac - 2;
    g_nums = malloc(sizeof(int) * g_size);
    int *set = calloc(g_size, sizeof(int));
    if (!g_nums || !set)
    {
        free(g_nums);
        free(set);
        return 1;
    }
    for (int i = 0; i < g_size; i++)
        g_nums[i] = atoi(av[i + 2]);
    solve(0, 0, 0, set);
    free(g_nums);
    free(set);
    return 0;
}