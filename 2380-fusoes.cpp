// Uso de union find

#include <bits/stdc++.h>

using namespace std;

vector<int> id, sz;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uniao (int p, int q){
    p = find(p);
    q = find(q);
    
    if (p == q) return;
    if (sz[p] > sz[q]) swap(p, q);
    id[p] = q;
    sz[q] += sz[p];
}

int main()
{
    
    int n, b;
    
    cin >> n >> b;
    
    id = vector<int> (n+1);
    sz = vector<int> (n+1, 1);
    iota(id.begin(), id.end(), 0); // inicializa o vector, semelhante ao for
    
    for(int i = 0; i < b; i++){
        char op;
        int p, q;
        
        cin >> op >> p >> q;
        
        if (op == 'C'){
            if (find(p) == find(q)) cout << "S\n";
            else cout << "N\n";
        } else uniao(p, q);
        
    }
    

    return 0;
}
