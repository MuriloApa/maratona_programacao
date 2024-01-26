#include <bits/stdc++.h>

using namespace std;

int main(){
    string telefone, aux;
    int i, pote, n, j;
    multiset<string> lista_tele;
    multiset<string>::iterator anterior, atual;

    while (cin >> n)
    {
        for ( i = 0; i < n; i++)
        {
            cin >> telefone;
            lista_tele.insert(telefone);
        }
        
        pote = 0;
        atual = lista_tele.begin();
        anterior = atual;
        atual++;
        //cout << "aqui\n\n";
        while (atual != lista_tele.end())
        {
            j = 0;
            aux = *anterior;
            telefone = *atual;
            //cout << aux << " " << telefone << endl;
            while (telefone[j] != '\0' && telefone[j] == aux[j])
            {
                j++;
            }
            pote += j;
            anterior = atual;
            atual++;
        }
        cout << pote << endl;
        lista_tele.clear();
    }
    
    return 0;
}
