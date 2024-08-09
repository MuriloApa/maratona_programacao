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

int main(){
    int r, c;
    int x, w, p;

    cin >> r >> c;

    id = vector<int> (r + 1);
    sz = vector<int> (r + 1, 1);
    iota(id.begin(), id.end(), 0);

    vector<tuple<int, int, int> > g;

    for (int i = 0; i < c; i++){
        cin >> x >> w >> p;

        g.emplace_back(p, x, w);

    }

    sort(g.begin(), g.end());

    int custo = 0;
    for(auto [w, a, b]: g){
        if (find(a) != find(b)){
            custo += w;
            uniao(a, b);
        }
    }
    
    cout << custo << endl;

    return 0;
}
