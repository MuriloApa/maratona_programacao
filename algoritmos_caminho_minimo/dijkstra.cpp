#include <bits/stdc++.h>

using namespace std;

typedef char vertice;

#define vertice_pos(x) (x - 'A') //o compilador faz a troca antes de compilar, substitui a chamada de funções, é melhor usar macros para chamadas simples
#define vertice_label(x) ((char)(x + 'A'))
#define INF INT_MAX

vector<set<pair<int, vertice>>> g;

void nova_aresta(vertice ori, vertice dest, int custo){
    g[vertice_pos(ori)].emplace(custo, dest);
    //g[vertice_pos(dest)].emplace(custo, ori); adicionar essa linha se o grafo não for dirigido
}

void mostra_grafo(){
    int i = 0;
    
    for(auto v: g){
        cout << vertice_label(i) << ": ";
        for (auto adj: v)
            cout << adj.first << adj.second << "\t";
        cout << endl;
        i++;
    }
}

vector<pair<int, vertice>> dijkstra(vertice ini){
    vector<pair<int, vertice>> caminho(g.size(), {INF, '*'});
    priority_queue<pair<int, vertice>> pq;
    
    pq.emplace(-0, ini);
    while(!pq.empty()){
        pair<int, vertice> p = pq.top();
        pq.pop();
        int dist = -p.first;
        vertice v = p.second;
        
        if (dist > caminho[vertice_pos(v)].first)
            continue;
        
        caminho[vertice_pos(v)].first = dist;
        
        for(auto adj: g[vertice_pos(v)]){
            int c = adj.first;
            int w = dist + c;
            vertice u = adj.second;

            if (caminho[vertice_pos(u)].first > w){
                pq.emplace(-w, u);
                caminho[vertice_pos(u)] = make_pair(w, v);
            }
        }
    }
    
    return caminho;
}

int main()
{
    g = vector<set<pair<int, vertice>>>(5);
    
    nova_aresta('E', 'A', 6);
    nova_aresta('E', 'B', 7);
    nova_aresta('A', 'B', 8);
    nova_aresta('A', 'D', 4);
    nova_aresta('A', 'C', 5);
    nova_aresta('B', 'C', 3);
    nova_aresta('B', 'D', 9);
    nova_aresta('C', 'A', 2);
    nova_aresta('D', 'C', 7);
    nova_aresta('D', 'E', 2);
    
    mostra_grafo();
    
    vertice ini = 'E';
    vector<pair<int, vertice>> cam = dijkstra(ini);

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