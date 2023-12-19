#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, i, maior;

    cin >> h;

    while (h > 0){
        maior = h;
        while(h > 1){
            if (h % 2 == 0)
                h /= 2;
            else
                h = 3 * h + 1;
            if (h > maior)
                maior = h;
        }
        cout << maior << "\n";
        cin >> h;
    }
    
    return 0;
}