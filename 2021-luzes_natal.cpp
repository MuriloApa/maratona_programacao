#include <bits/stdc++.h>

using namespace std;

int main()
{
    int altura, largura, p, i, q, lights;

    cin >> altura >> largura >> p;

    while (altura > 0 && largura > 0 && p > 0)
    {
        lights = 0;
        for (i = 0; i < p; i++)
        {
            cin >> q;
            //cout << q << endl;
            if (q <= largura)
            {
                lights += largura - q + 1;
            } else {
                if (q % largura == 0)
                {
                    lights += 1;
                } else {
                    lights += largura - (q % largura) + 1;
                }
            }
        }
        cout << "Lights: " << lights << endl;
        cin >> altura >> largura >> p;
    }

    return 0;
}
