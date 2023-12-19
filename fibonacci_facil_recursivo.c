#include <stdio.h>

void fib(int n, int ant1, int ant2)
{
    int aux;
    if (n > 0)
    {
        printf("%d ", ant1);
        aux = ant2;
        ant2 = ant1 + ant2;
        ant1 = aux;
        return fib(n - 1, ant1, ant2);
    }

    printf("\n");
}

int main()
{
    int n;

    scanf("%d", &n);
    fib(n, 0, 1);

    return 0;
}