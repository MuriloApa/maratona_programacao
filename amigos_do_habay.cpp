#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> n_amigos;
    multimap<int, pair<string, int>> amigos;
    string amigo, eh_amigo;
    int i = 0;
    
    cin >> amigo;
    while (amigo != "FIM"){
        cin >> eh_amigo;
        
        if( eh_amigo == "YES"){
            amigos.insert({amigo.length(), make_pair(amigo, i++)});
        } else {
            n_amigos.insert(amigo);
        }
        
        cin >> amigo;
    }
    
    for(auto i: amigos){
        cout << i.second.first << endl;
    }
    
    for(auto i: n_amigos){
        cout << i << endl;
    }
    
    cout << '\n';
    
    auto comeco = amigos.begin();
    auto range = amigos.equal_range(comeco.first);

    pair<string, int> menor;
    menor.first = range.second.first;
    menor.second = range.second.second;
    range++;
    
    for(auto elemento = range.first; elemento != range.second; elemento++ ){
        
        if (elemento.second.second < menor.second.second){
            menor = elemento;
        }
    }
    
    cout << "Amigo do Habay:\n" << menor.first;

    return 0;
}
