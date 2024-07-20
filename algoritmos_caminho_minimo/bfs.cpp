#include <bits/stdc++.h>

using namespace std;

typedef char vertice;

#define vertice_pos(x) (x - 'A') //o compilador faz a troca antes de compilar, substitui a chamada de funções, é melhor usar macros para chamadas simples
#define vertice_label(x) ((char)(x + 'A'))
#define INF INT_MAX

vector<set<vertice>> g;

void nova_aresta(vertice ori, vertice dest){
    g[vertice_pos(ori)].insert(dest);
    g[vertice_pos(dest)].insert(ori);
}

void mostra_grafo(){
    int i = 0;
    
    for(auto v: g){
        cout << vertice_label(i) << ": ";
        for (auto adj: v)
            cout << adj << " ";
        cout << endl;
        i++;
    }
}

vector<pair<int, vertice>> bfs(vertice ini){
    vector<pair<int, vertice>> caminho(g.size(), {0, '*'});
    vector<bool> vis(g.size(), false);
    queue<pair<int, vertice>> q;
    
    q.emplace(0, ini);
    while(!q.empty()){
        pair<int, vertice> p = q.front();
        q.pop();
        int dist = p.first;
        vertice v = p.second;
        
        if (vis[vertice_pos(v)])
            continue;
        
        vis[vertice_pos(v)] = true;
        
        for(auto adj: g[vertice_pos(v)]){
            if (!vis[vertice_pos(adj)]){
                q.emplace(dist + 1, adj);
                if (caminho[vertice_pos(adj)].second == '*')
                    caminho[vertice_pos(adj)] = make_pair(dist + 1, v);
            }
        }
    }
    
    return caminho;
}

int main()
{
    g = vector<set<vertice>>(7);
    
    nova_aresta('A', 'B');
    nova_aresta('A', 'C');
    nova_aresta('A', 'D');
    nova_aresta('A', 'E');
    nova_aresta('C', 'D');
    nova_aresta('D', 'G');
    nova_aresta('D', 'E');
    nova_aresta('E', 'F');
    nova_aresta('E', 'G');
    
    mostra_grafo();
    
    vertice ini = 'A';
    vector<pair<int, vertice>> cam = bfs(ini);
    
    /* distancia */
    cout << "Distâncias: \n";
    for(int i = 0; i < cam.size(); i++){
        cout << ini << " -> " << vertice_label(i) << " = " << cam[i].first << endl;
    }
    
    /* caminhos */
    cout << "\nCaminhos\n";
    for(int i = 0; i < cam.size(); i++){
        cout << ini << " -> " << vertice_label(i) << " = " ;
        
        stack<vertice> s;
        s.push(vertice_label(i));
        while(s.top() != ini){
            s.push(cam[vertice_pos(s.top())].second);
        }
        
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        
        cout << endl;
    }
    
    return 0;
}