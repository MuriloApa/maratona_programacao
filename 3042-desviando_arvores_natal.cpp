#include <bits/stdc++.h>

using namespace std;

int main(){
    int pista[3], i, aux, n;
    pair<int, int> toques;

    cin >> n;
    while (n > 0)
    {
        toques.first = 1;
        toques.second = 0;
        for ( i = 0; i < n; i++)
        {
            cin >> pista[0];
            cin >> pista[1];
            cin >> pista[2];
            
            if (pista[toques.first] == 1)
            {
                if (pista[0] == 0)
                {
                    toques.second += abs(0 - toques.first);
                    toques.first = 0;
                } else if (pista[1] == 0)
                {
                    toques.second += abs(1 - toques.first);
                    toques.first = 1;
                }else if (pista[2] == 0)
                {
                    toques.second += abs(2 - toques.first);
                    toques.first = 2;
                }
                
            }
            
        }
        cout << toques.second << endl;
        cin >> n;
    }
    
    return 0;
}
