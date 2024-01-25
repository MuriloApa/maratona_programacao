#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<int> fila;
    priority_queue<int> prio;
    stack<int> pilha;
    int op, numero, n, i, fila_ver, prio_ver, pilha_ver, soma;

    while (cin >> n)
    {
        fila_ver = 1; prio_ver = 1; pilha_ver = 1;
        for ( i = 0; i < n; i++)
        {
            cin >> op >> numero;

            if (op == 1)
            {
                fila.push(numero);
                prio.push(numero);
                pilha.push(numero);
            } else {
                if (fila.front() != numero)
                    fila_ver = 0;
                if ( prio.top() != numero )
                    prio_ver = 0;
                if ( pilha.top() != numero )
                    pilha_ver = 0;

                fila.pop(); prio.pop(); pilha.pop();
            }
            
        }

        int soma = fila_ver + prio_ver + pilha_ver;
        if (soma == 0)
        {
            cout << "impossible\n";
        } else {
            if (soma >= 2)
            {
                cout << "not sure\n"; //<< "fila: " << fila_ver << "\nprio: " << prio_ver << "\npilha: " << pilha_ver << endl;
            } else {
                if ( fila_ver )
                    cout << "queue\n";
                if (prio_ver)
                    cout << "priority queue\n";
                if (pilha_ver)
                    cout << "stack\n";
            }
            
        }
        
        while (!fila.empty())
        {
            fila.pop();
        }

        while (!pilha.empty()){
            pilha.pop();
        }

        while (!prio.empty())
        {
            prio.pop();
        }
        
        
    }
    
    return 0;
}
