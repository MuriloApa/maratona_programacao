#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, custo, atual, maior;
    
    while (cin >> n){
        cin >> custo;
        
        vector<int> receita(n);
        for(int i = 0; i < n; i++){
            int re;
            cin >> receita[i];
            receita[i] -= custo;
        }
        
        maior = numeric_limits<int>::min();
        atual = 0;

        for(auto x: receita){
            atual = max(atual + x, x);
            maior = max(atual, maior);
        }
        
        if (maior > 0) cout << maior << endl;
        else cout << 0 << endl;

        receita.clear();
    }

    return 0;
}
