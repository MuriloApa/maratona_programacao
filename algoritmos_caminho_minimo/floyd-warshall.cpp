#include <bits/stdc++.h>

using namespace std;

typedef char vertice;

#define vertice_pos(x) (x - 'A') //o compilador faz a troca antes de compilar, substitui a chamada de funções, é melhor usar macros para chamadas simples
#define vertice_label(x) ((char)(x + 'A'))
#define INF INT_MAX

vector<vector<int>> g;

void nova_aresta(vertice ori, vertice dest, int custo){
    g[vertice_pos(ori)][vertice_pos(dest)] = custo;
}

void mostra_grafo(){
    int i = 0;
    
    for(auto v: g){
        cout << vertice_label(i) << ": ";
        for (auto adj: v){
            if(adj == INF) cout << "\tinf";
            else cout << "\t" << adj;
        }
            
        cout << endl;
        i++;
    }
}

void mostra_grafo(vector<vector<pair<int, vertice>>> G){
    int i = 0;
    
    for(auto v: G){
        cout << vertice_label(i) << ": ";
        for (auto adj: v){
            if(adj.first == INF) cout << "\tinf";
            else cout << "\t" << adj.first;
        } 
        cout << endl;
        i++;
    }
}

vector<vector<pair<int, vertice>>> floydwarshall(){
    vector<vector<pair<int, vertice>>> caminhos(g.size(), vector<pair<int, vertice>>(g.size(), {0, '*'}));

    

    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g.size(); j++){
            caminhos[i][j].first = g[i][j];
            if(g[i][j] != 0 && g[i][j] != INF)
                caminhos[i][j].second = vertice_label(i);
        }
    }

    for (int k = 0; k < g.size(); k++) {
        /* cout << "\nD" << k << endl;
        mostra_grafo(caminhos); */
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g.size(); j++){
                if (caminhos[i][k].first == INF || caminhos[k][j].first == INF)
                    continue;
                int c = caminhos[i][k].first + caminhos[k][j].first;
                if (caminhos[i][j].first > c){
                    caminhos[i][j].first = c;
                    caminhos[i][j].second = caminhos[k][j].second;
                }
            }
        }
        
    }
    
    return caminhos;
}

int main()
{
    g = vector(5, vector<int>(5, INF));

    for(int i = 0; i < 5; i++){
        g[i][i] = 0;
    }
    
    nova_aresta('A', 'B', 3);
    nova_aresta('A', 'C', 8);
    nova_aresta('A', 'E', -4);
    nova_aresta('B', 'E', 7);
    nova_aresta('B', 'D', 1);
    nova_aresta('C', 'B', 4);
    nova_aresta('D', 'A', 2);
    nova_aresta('D', 'C', -5);
    nova_aresta('E', 'D', 6);
    
    mostra_grafo();
    
    vector<vector<pair<int, vertice>>> cam = floydwarshall();

    /* distancia */
    cout << "Distâncias: \n";
    for(int i = 0; i < cam.size(); i++){
        cout << vertice_label(i) << " ->";

        for(int j = 0; j < cam.size(); j++)
            cout << "\t" << vertice_label(j) << cam[i][j].first;
        cout << endl;
    }

    /* caminhos */
    cout << "\nCaminhos\n";
    for(int i = 0; i < cam.size(); i++){

        for(int j = 0; j < cam.size(); j++){
            cout << vertice_label(i) << " -> " << vertice_label(j) << " = ";
            stack<vertice> s;
            s.push(vertice_label(j));
            while(s.top() != vertice_label(i)){
                s.push(cam[i][vertice_pos(s.top())].second);
            }
            
            while(!s.empty()){
                cout << s.top() << " ";
                s.pop();
            }
            
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}