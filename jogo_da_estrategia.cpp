#include <bits/stdc++.h>

using namespace std;

int main(){
    int j, r, i, jogadas, jogada, ganhador;

    cin >> j >> r;

    int jogadores[j] = {};
    jogadas = j * r;
    for ( i = 0; i < jogadas; i++)
    {
        cin >> jogada; 
        jogadores[i%j] += jogada;
    }

    ganhador = 0;
    for ( i = 1; i < j; i++)
    {
        if (jogadores[i] >= jogadores[ganhador])
            ganhador = i;
    }

    cout << ganhador + 1 << "\n";
    
    return 0;
}