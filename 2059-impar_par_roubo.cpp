#include <bits/stdc++.h>

using namespace std;

int main(){
    int p, j1, j2, r, a, soma;

    cin >> p >> j1 >> j2 >> r >> a;

    if ((r == 1 && a == 0) || (r == 0 && a == 1)){
        cout << "Jogador 1 ganha!\n";
    }else if (r == 1 && a == 1)
    {
        cout << "Jogador 2 ganha!\n";
    } else {
        soma = j1 + j2;
        if (soma % 2 == 0)
        {
            if (p)
            {
                cout << "Jogador 1 ganha!\n";
            } else {
                cout << "Jogador 2 ganha!\n";
            }
            
        } else {
            if (!p)
            {
                cout << "Jogador 1 ganha!\n";
            } else {
                cout << "Jogador 2 ganha!\n";
            }
        }
        
    }
    

    return 0;
}
