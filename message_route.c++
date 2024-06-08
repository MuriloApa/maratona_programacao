/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

vector<bool> vis(MAX);
vector<vector<int>> g(MAX); //grafo
//vector<int> dist(MAX, 0);
vector<int> pai(MAX, -1);

void bfs(int s){
	pai[s] = s;

	queue<int> q;
	q.push(s);
	vis[s] = true;
	//dist[s] = 1;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto u: g[v]){
			if (!vis[u]){
				vis[u] = true;
				//dist[u] = dist[v] + 1;
				pai[u] = v;
				q.push(u);
				
				
			}
		}
	}
}


vector<int> path(int v){
    vector<int> caminho;
    
    if (pai[v] == -1)
        return caminho;
        
    while(pai[v] != v){
        caminho.push_back(v);
        v = pai[v];
    }
    caminho.push_back(v);
    reverse(caminho.begin(), caminho.end());
    return caminho;
}


int main()
{
    int n, m, a, b;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    bfs(0);
    vector<int> caminho = path(n-1);
    
    if (caminho.size() > 0){
        cout << caminho.size();
        cout << endl;
        for(auto u: caminho){
            cout << u + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    
    
    
    return 0;
}
