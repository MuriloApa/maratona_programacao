#include <stdio.h>

int main()
{
    int n, i, atual = 0, proximo = 1, aux;

    scanf("%d", &n);
    if (n > 0)
    {
        for (i = 0; i < n - 1; i++)
        {
            printf("%d ", atual);
            aux = proximo;
            proximo = proximo + atual;
            atual = aux;
        }
        printf("%d\n", atual);
    }

    return 0;
}