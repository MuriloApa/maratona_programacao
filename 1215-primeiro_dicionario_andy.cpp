#include <bits/stdc++.h>

using namespace std;

void converte_minuscula(string &palavra){
    string::iterator letra;
    for(letra = palavra.begin(); letra != palavra.end(); letra++){
        *letra = tolower(*letra);
    }
}

void exibe_palavras(set<string> palavras){
    for(auto palavra: palavras){
        cout << palavra << endl;
    }
}

int main(){
    set<string> palavras;
    string palavra;
    regex regex("[^a-zA-Z]+");

    
    while(cin >> palavra){
        
        converte_minuscula(palavra);
        sregex_token_iterator it(palavra.begin(), palavra.end(), regex, -1);
        sregex_token_iterator end;

        while (it != end)
        {
            if (it->length() > 0)
            {
                palavras.insert(*it);
            }
            it++;
        }
        
    }

    exibe_palavras(palavras);
    return 0;
}
