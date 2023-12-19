#include <stdio.h>

int main(void)
{

    int linha, i, j;
    float matriz[12][12], acumulador = 0;
    char op;

    scanf("%d", &linha);
    scanf("\n%c", &op);
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 12; j++)
        {
            scanf("%f", &matriz[i][j]);
            if (i == linha)
            {
                acumulador = acumulador + matriz[i][j];
            }
        }
    }

    switch (op)
    {
    case 'S':
        printf("%.1f\n", acumulador);
        break;
    case 'M':
        printf("%.1f\n", acumulador/12);
        break;

    default:
        break;
    }
    return 0;
}