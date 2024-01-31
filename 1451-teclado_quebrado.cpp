#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<string> beijus;
    string frase, aux, final, prev;
    int i;
    char c;

    while (cin >> frase)
    {
        prev = "";
        final = "";
        for (i = 0; i < frase.size(); i++)
        {
            //cout << "1 - aqui\n";
            if (frase[i] == '[')
            {
                //cout << "2 - aqui\n";
                while (frase[i] == '[')
                {
                    //cout << "3 - aqui\n";
                    aux = "";
                    i++;
                    while (i < frase.size() && frase[i] != '[' && frase[i] != ']')
                    {
                        //cout << "4 - aqui\n";
                        aux += frase[i];
                        i++;
                    }
                    //cout << "5 - aqui\n";
                    beijus.push(aux);
                }
            }
            else
            {
                if (frase[i] != ']')
                {
                    prev += frase[i];
                }
            }
        }
        while (!beijus.empty())
        {
            final += beijus.top();
            beijus.pop();
        }
        final += prev;
        final += "\n";
        cout << final;
    }

    return 0;
}
