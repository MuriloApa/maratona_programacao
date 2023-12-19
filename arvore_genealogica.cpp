#include <bits/stdc++.h>

using namespace std;

int main(){
    multimap<string, string> relacoes;
    vector<set<string>> familias;
    vector<int> posicoes;
    string no1, no2, linha, aux;
    int m, n, i, j, orfao;

    cin >> m >> n;
    for ( i = 0; i < n; i++)
    {
        getline(cin >> ws, linha);
        istringstream stream(linha);
        for ( j = 0; j < 3; j++)
        {
            getline(stream, no1, ' ');
            getline(stream, aux, ' ');
            getline(stream, no2, ' ');
            
        }
        relacoes.insert(make_pair(no1, no2));
    }
    //cout << "\n\n";
    for (auto elemento: relacoes)
    {
        orfao = 0;
        
        for (i = 0; i < familias.size(); i++){
            
            if (familias[i].count(elemento.first) > 0 || 
                familias[i].count(elemento.second) > 0){
                    familias[i].insert(elemento.first);
                    familias[i].insert(elemento.second);
                    orfao++;
                    posicoes.push_back(i);
                    //cout << elemento.first << " " << elemento.second << "\n\n";
            }
        }
        
        if (!orfao){
            familias.push_back({elemento.first, elemento.second});
        } else {
            if (orfao > 1)
            {
                set<string> auxiliar;
                for (auto posicao: posicoes)
                {
                    for (auto membro: familias[posicao])
                    {
                        auxiliar.insert(membro);
                    }
                }
                for (auto posicao: posicoes)
                {
                    familias.erase(familias.begin() + posicao);
                }
                familias.push_back(auxiliar);
            }
            
        }
        posicoes.clear();
    }

/*
    for (auto elemento: familias)
    {
        cout << "Família: ";
        for (auto membro: elemento){
            cout << membro << " ";
        }
        cout << "\n";
    }*/
    
    cout << familias.size() << "\n";
    
    return 0;
}