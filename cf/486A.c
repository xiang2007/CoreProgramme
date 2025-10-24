#include <stdio.h>

int main()
{
    long long fn;
    scanf("%lld", &fn);
    long long res;

    if (fn % 2 == 0)
        res = fn / 2;
    else
        res = -(fn + 1) / 2;

    printf("%lld\n", res);
    return 0;
}
