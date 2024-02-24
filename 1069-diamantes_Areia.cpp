#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<char> pilha;
    char atual;
    string mina;
    int diamantes, i, n, j;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> mina;
        j = 0;
        diamantes = 0;
        while (mina[j] != '\0')
        {
            if (mina[j] == '<')
            {
                pilha.push(mina[j]);
            }
            if (mina[j] == '>' && pilha.size() > 0)
            {
                pilha.pop();
                diamantes++;
            }
            j++;
            // cout << j << endl;
        }
        while (!pilha.empty())
        {
            pilha.pop();
        }

        cout << diamantes << endl;
    }

    return 0;
}
