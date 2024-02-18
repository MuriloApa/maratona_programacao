#include <bits/stdc++.h>

using namespace std;

void print_container(vector<int> &c){
    cout << "\nvetor: ";
    for (auto i: c)
    {
        cout << i << " ";
    }
    cout << "\n\n";
    
}

int main()
{
    int n, f, c, i, passo = 1, j, atual, total = 1;
    vector<int> numeros;
    vector<int>::iterator it;

    cin >> n >> f >> c;

    atual = n * f + c + 1;
    for (i = 1; i <= n * n; i++)
    {
        if (i != atual)
        {
            numeros.push_back(i);
        }
    }

    cout << atual;
    while (!numeros.empty())
    {
        //print_container(numeros);
        //  direita
        for (j = 0; j < passo; j++)
        {
            if (numeros.empty())
            {
                break;
            }
            // cout << "AQUI - " << passo << "\n\n";
            atual = f * n + c + 1 + 1;
            if (f >= 0 && f < n && c + 1 >= 0 && ((c + 1) < n))
            {
                it = lower_bound(numeros.begin(), numeros.end(), atual);
                if (it != numeros.end() && *it == atual)
                {
                    //printf("\nA excluir: %d - atual: %d\n", *it, atual);
                    numeros.erase(it);
                }
            }

            c += 1;
            if (f < n && f >= 0 && c < n && c >= 0)
                cout << " " << f * n + c + 1;
            total += 1;
        }

        // baixo
        for (j = 0; j < passo; j++)
        {
            if (numeros.empty())
            {
                break;
            }

            atual = f * n + c + n + 1;
            if (f + 1 >= 0 && ((f + 1) < n) && c >= 0 && c < n)
            {
                it = lower_bound(numeros.begin(), numeros.end(), atual);
                if (it != numeros.end() && *it == atual)
                {
                    //printf("\nA excluir: %d - atual: %d\n", *it, atual);
                    numeros.erase(it);
                }
            }

            f += 1;
            if (f < n && f >= 0 && c < n && c >= 0)
                cout << " " << f * n + c + 1;
            total += 1;
        }

        // esquerda
        for (j = 0; j < passo + 1; j++)
        {
            if (numeros.empty())
            {
                break;
            }

            atual = f * n + c;
            if (f >= 0 && f < n && c - 1 >= 0 && ((c - 1) < n))
            {
                it = lower_bound(numeros.begin(), numeros.end(), atual);
                if (it != numeros.end() && *it == atual)
                {
                    //printf("\nA excluir: %d - atual: %d\n", *it, atual);
                    numeros.erase(it);
                }
            }

            c -= 1;
            if (f < n && f >= 0 && c < n && c >= 0)
                cout << " " << f * n + c + 1;
            total += 1;
        }

        // cima
        for (j = 0; j < (passo + 1); j++)
        {
            if (numeros.empty())
            {
                break;
            }

            atual = f * n + c - n + 1;
            if (f - 1 >= 0 && (f - 1 < n) && c >= 0 && c < n)
            {
                it = lower_bound(numeros.begin(), numeros.end(), atual);
                if (it != numeros.end() && *it == atual)
                {
                    //printf("\nA excluir: %d - atual: %d\n", *it, atual);
                    numeros.erase(it);
                }
            }

            f -= 1;
            if (f < n && f >= 0 && c < n && c >= 0)
                cout << " " << f * n + c + 1;
            total += 1;
        }
        passo += 2;
    }

    cout << "\n" << total << endl;

    return 0;
}
