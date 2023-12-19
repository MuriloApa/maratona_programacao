#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

int main(){
    set<string> lista;
    int n, i;
    string linha, item;
    

    cin >> n;
    for (i = 0; i < n; i++)
    {
        getline(cin >> ws, linha);
        istringstream stream(linha);
        while (getline(stream, item, ' '))
        {
            lista.insert(item);
        }
        for (auto elemento: lista)
        {
            if (elemento == *(--lista.end()))
            {
                cout << elemento << "\n";
            } else {
                cout << elemento << " ";
            }
        }
        lista.clear();
    }
    
    return 0;
}