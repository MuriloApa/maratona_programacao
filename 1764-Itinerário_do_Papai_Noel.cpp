// Uso do algoritmo de kruskal com Union Find

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
    int n, m; // n = cidades, m = caminhos
    
    cin >> n >> m;
    
    while (m != 0 && n != 0){
        int x, y, z;
        vector<tuple<int, int, int>> g;
        
        for(int i = 0; i < m; i++){
            cin >> x >> y >> z;
            g.emplace_back(z, x, y);
        }
        
        sort(g.begin(), g.end());
        
        id = vector<int> (n+1);
        sz = vector<int> (n+1, 1);
        iota(id.begin(), id.end(), 0);
        
        int custo = 0;
        for (auto [w, a, b]: g){
            if(find(a) != find(b)){
                uniao(a, b);
                custo += w;
            }
        }
        
        cout << custo << endl;
        
        cin >> n >> m;
    }
    
    
    
    return 0;
}
