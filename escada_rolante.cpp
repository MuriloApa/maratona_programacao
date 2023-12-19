#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, i, t, acumulado, antigo;

    cin >> n;

    while (n != 0){
        acumulado = 10;
        cin >> t;
        antigo = t;
        for ( i = 1; i < n; i++)
        {
            cin >> t;
            if (t - antigo < 10)
            {
                acumulado += (t - antigo);
            } else {
                acumulado += 10;
            }
            antigo = t;
        }
        cout << acumulado << "\n";
        cin >> n;
    }
    
    return 0;
}