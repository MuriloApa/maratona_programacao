#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maior, menor, i, presente, soma;
    vector<int> presentes;
    cin >> n;

    while (n > 0)
    {
        for ( i = 0; i < 2 * n; i++)
        {
            cin >> presente;
            presentes.push_back(presente);
        }
        soma = presentes[0] + presentes[2*n-1];
        maior = soma;
        menor = soma;
        for ( i = 1; i < n; i++)
        {
            soma = presentes[i] + presentes[2*n-i-1];
            if (soma > maior)
            {
                maior = soma;
            }
            if (soma < menor)
            {
                menor = soma;
            }
            
        }
        printf("%d %d\n", maior, menor);
        presentes.clear();
        cin >> n;
    }
    
    return 0;
}