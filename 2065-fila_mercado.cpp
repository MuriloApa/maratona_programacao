#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, i, t;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fila;
    pair<int, pair<int, int>> aux;
    vector<int> itens;

    cin >> n >> m;

    for (i = 0; i < n; i++){
        cin >> t;
        fila.emplace(0, make_pair(i, t));
    }

    for (i = 0; i < m; i++){
        cin >> t;
        itens.push_back(t);
    }

    /* while (!fila.empty()){
        cout << fila.top().first << ", " << fila.top().second.first << ", " << fila.top().second.second << '\n';
        fila.pop();
    } */

    for(auto item: itens){
        aux.first = fila.top().first + fila.top().second.second * item;
        aux.second.first = fila.top().second.first;
        aux.second.second = fila.top().second.second;
        fila.pop();
        fila.emplace(aux);
    }

    /* while (!fila.empty())
    {
        cout << fila.top().first << ", " << fila.top().second.second << '\n';
        fila.pop();
    }  */

    while (fila.size() != 1){
        fila.pop();
    }
    cout << fila.top().first << endl;
    
    return 0;
}
