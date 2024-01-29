#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<pair<int, pair<char, string>>, vector<pair<int, pair<char, string>>>, greater<>> criancas;
    string crianca;
    char reg;
    int dist, q, i;

    while (cin >> q)
    {
        for (i = 0; i < q; i++)
        {
            cin >> crianca >> reg >> dist;
            criancas.emplace(dist, make_pair(reg, crianca));
        }

        while (!criancas.empty())
        {
            cout << criancas.top().second.second << endl; //" " << criancas.top().second.first << ' ' << criancas.top().first << endl;
            criancas.pop();
        }
    }

    return 0;
}
