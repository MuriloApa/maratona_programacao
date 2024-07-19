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

float distancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1, 2));
}

int main()
{
    int c;
    
    cin >> c;
    
    for (int i = 0; i < c; i++){
        int n;
        cin >> n;
        
        id = vector<int> (n + 1);
        sz = vector<int> (n + 1, 1);
        iota(id.begin(), id.end(), 0);
        
        vector<pair<double, double>> coor;
        for(int j = 0; j < n; j++){
            float x, y;
            cin >> x >> y;
            coor.emplace_back(x, y);
        }
        
        vector<tuple<double, int, int> > g;
        
        for(int k = 1; k < n; k++){
            for(int l = 0; l < k; l++){
                g.emplace_back(distancia(coor[k].first, coor[k].second, coor[l].first, coor[l].second), k, l);
            }
        }
        
        sort(g.begin(), g.end());
        
        double custo = 0;
        for(auto [w, a, b]: g){
            if (find(a) != find(b)){
                custo += w;
                uniao(a, b);
            }
        }
        
        //cout << custo << endl;
        printf("%.2lf\n", custo/100);
    }

    return 0;
}
