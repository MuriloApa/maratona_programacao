#include <stdio.h>

int main()
{
    int i, qtd, escadinhas = 0;
    long n_atual, n_anterior = 0, dif_atual;

    scanf("%d", &qtd);

    scanf("%ld", &n_atual);
    if (qtd > 1)
    {
        n_anterior = n_atual;
        scanf("%ld", &n_atual);
        dif_atual = n_atual - n_anterior;
        escadinhas++;

        for (i = 2; i < qtd; i++)
        {
            n_anterior = n_atual;
            scanf("%ld", &n_atual);
            if (n_atual - n_anterior != dif_atual)
            {
                escadinhas++;
                dif_atual = n_atual - n_anterior;
            }
        }
    }

    printf("%d\n", escadinhas);
    return 0;
}