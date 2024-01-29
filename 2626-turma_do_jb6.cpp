#include <bits/stdc++.h>

using namespace std;

/*
1 - vitoria
0 - empate ou derrota
*/

bool is_winner(string player1, string player2){
    
    if (player1 == "pedra" && player2 == "tesoura")
    {
        return true;
    }
    if (player1 == "papel" && player2 == "pedra")
    {
        return true;
    }
    if (player1 == "tesoura" && player2 == "papel")
    {
        return true;
    }
    return false;
}

int main(){
    pair<bool, pair<string, string>> dodo;
    pair<bool, pair<string, string>> leo;
    pair<bool, pair<string, string>> pepper;
    string j1, j2, j3;
    int vencedores;

    dodo.second.second = "Os atributos dos monstros vao ser inteligencia, sabedoria...\n";
    leo.second.second = "Iron Maiden's gonna get you, no matter how far!\n";
    pepper.second.second = "Urano perdeu algo muito precioso...\n";

    while (cin >> j1 >> j2 >> j3)
    {
        dodo.second.first = j1;
        leo.second.first = j2;
        pepper.second.first = j3;

        dodo.first = false;
        leo.first = false;
        pepper.first = false;

        dodo.first = dodo.first ||is_winner(dodo.second.first, leo.second.first);
        dodo.first = dodo.first || is_winner(dodo.second.first, pepper.second.first);

        leo.first = leo.first || is_winner(leo.second.first, dodo.second.first);
        leo.first = leo.first || is_winner(leo.second.first, pepper.second.first);

        pepper.first = pepper.first || is_winner(pepper.second.first, leo.second.first);
        pepper.first = pepper.first || is_winner(pepper.second.first, dodo.second.first);

        vencedores = dodo.first + leo.first + pepper.first;

        //cout << vencedores << "\n";
        if (vencedores > 1 || vencedores == 0)
        {
            cout << "Putz vei, o Leo ta demorando muito pra jogar...\n";
        } else {
            if (dodo.first)
                cout << dodo.second.second;
            if (leo.first)
                cout << leo.second.second;
            if (pepper.first)
                cout << pepper.second.second;
        }
        
    }
    
    return 0;
}
