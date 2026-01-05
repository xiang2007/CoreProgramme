#include <stdio.h>
#include <stdlib.h>

int *a, *s, n, t;

void dfs(int i, int sum, int k)
{
    if (sum == t)
    {
        for (int j = 0; j < k; j++)
            printf("%d%s", s[j], j + 1 < k ? " " : "");
        printf("\n");
        return;
    }
    if (i == n)
        return;
    s[k] = a[i];
    dfs(i + 1, sum + a[i], k + 1);
    dfs(i + 1, sum, k);
}

int main(int c, char **v)
{
    if (c < 2)
        return 0;
    t = atoi(v[1]);
    n = c - 2;
    a = malloc(sizeof(int) * n);
    s = malloc(sizeof(int) * n);
    if (!a || !s)
        return 1;
    for (int i = 0; i < n; i++)
        a[i] = atoi(v[i + 2]);
    dfs(0, 0, 0);
    free(a);
    free(s);
}
