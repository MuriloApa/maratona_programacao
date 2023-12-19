#include <bits/stdc++.h>

using namespace std;

int main() {
 
    int i, j, atacantes[11], a, d, defensores[11], impedido, menor;
    
    cin >> a >> d;

    while(a != 0 && d != 0){
        impedido = 0;

        for(i = 0; i < a; i++){
            cin >> atacantes[i];
        }
        
        for (i = 0; i < d; i++){
            cin >> defensores[i];
        }
        
        for (i = 1; i < d; i++){
            menor = defensores[i];
            j = i;
            while (j > 0 && menor < defensores[j-1])
            {
                defensores[j] = defensores[j-1];
                j--;
            }
            defensores[j] = menor;
        }
        
        i = -1;
        while (++i < a && !impedido){
            // cout << "Atacante " << i << " " << atacantes[i] << "\n";
            if ((defensores[1] != defensores[0] && atacantes[i] < defensores[1]) || 
            (defensores[0] == defensores[1] && atacantes[i] < defensores[1])){
                impedido = 1;
            }
        }
        
        //cout << "Último: " << defensores[0] << "\nPenultimo: " << defensores[1] << "\n";
        
        if (impedido)
            cout << "Y\n";
        else
            cout << "N\n";

        cin >> a >> d;
    }    
    return 0;
}
