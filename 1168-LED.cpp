#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, qtd;
    string numero;

    cin >> n;
    
    for(i = 0; i < n; i++){
        
        cin >> numero;
        
        int j = -1;
        qtd = 0;
        while(numero[++j] != '\0'){
            if (numero[j] == '1')
                qtd += 2;
                
            if (numero[j] == '2' || numero[j] == '3' || numero[j] == '5')
                qtd += 5;
                
            if (numero[j] == '4')
                qtd += 4;
                
            if (numero[j] == '6' || numero[j] == '9' || numero[j] == '0')
                qtd += 6;
                
            if (numero[j] == '7')
                qtd += 3;
                
            if (numero[j] == '8')
                qtd += 7;
        }
        cout << qtd << " leds\n";
    } 

    return 0;
}
