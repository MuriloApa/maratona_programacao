#include <bits/stdc++.h>

using namespace std;

list<pair<string, int>>::iterator avancar_horario(list<pair<string, int>> &fila, int avanco, list<pair<string, int>>::iterator atual)
{
    for (int i = 0; i < avanco; i++)
    {
        if (atual == fila.begin())
        {
            atual = --fila.end();
        } else {
            atual--;
        }
    }

    return atual;
}

list<pair<string, int>>::iterator avancar_anti_horario(list<pair<string, int>> &fila, int avanco, list<pair<string, int>>::iterator atual)
{
    for (int i = 0; i < avanco; i++)
    {
        ++atual;
        if (atual == fila.end())
        {
            atual = fila.begin();
        }
    }

    return atual;
}

pair<list<pair<string, int>>::iterator, int> excluir(list<pair<string, int>> &fila, int avanco, list<pair<string, int>>::iterator atual, int not_first)
{
    list<pair<string, int>>::iterator remover, proximo;
    pair<list<pair<string, int>>::iterator, int> next;

    // cout << "\nAvanço: " << avanco << endl;
    if ((avanco + not_first) % 2 == 0)
    {
        remover = avancar_horario(fila, avanco, atual);
        proximo = avancar_horario(fila, 1, remover);
        next.first = proximo;
        next.second = remover->second;
        /* cout << "\nPar\n";
        cout << "Atual: " << atual->first << " ";
        cout << "Remover: " << remover->first << " ";
        cout << "Próximo: " << proximo->first << " "; */
    }
    else
    {
        remover = avancar_anti_horario(fila, avanco, atual);
        proximo = avancar_anti_horario(fila, 1, remover);
        next.first = proximo;
        next.second = remover->second;
        /* cout << "\nÍmpar\n";
        cout << "Atual: " << atual->first << " ";
        cout << "Remover: " << remover->first << " ";
        cout << "Próximo: " << proximo->first << " "; */
    }

    fila.erase(remover);
    return next;
}

void imprime_circulo(list<pair<string, int>> teste)
{
    for (auto it : teste)
    {
        cout << it.first << ", " << it.second << endl;
    }
}

int main()
{
    list<pair<string, int>> circulo;
    string crianca;
    int avanco, n;

    cin >> n;

    while (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> crianca;
            cin >> avanco;
            circulo.push_back(make_pair(crianca, avanco));
        }

        pair<list<pair<string, int>>::iterator, int> quianca;
        quianca.first = circulo.begin();
        quianca.second = quianca.first->second;
        quianca = excluir(circulo, quianca.second, quianca.first, 0);
        /* cout << endl;
        imprime_circulo(circulo);
        cout << endl; */

        while (circulo.size() != 1)
        {
            quianca = excluir(circulo, quianca.second - 1, quianca.first, 1);
            /* cout << endl;
            imprime_circulo(circulo);
            cout << endl; */
        }

        cout << "Vencedor(a): " << quianca.first->first << endl;
        circulo.clear();
        cin >> n;
    }

    return 0;
}
