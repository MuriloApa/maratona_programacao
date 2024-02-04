#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, aux;
    multiset<int> pares;
    multiset<int, greater<int>> impares;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> aux;

        if (aux % 2 == 0)
        {
            pares.insert(aux);
        }
        else
        {
            impares.insert(aux);
        }
    }

    for (auto number : pares)
    {
        cout << number << endl;
    }

    for (auto number : impares)
    {
        cout << number << endl;
    }

    return 0;
}
