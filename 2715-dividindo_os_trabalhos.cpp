#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> tarefas;
	int i, n, aux;
	long long int rangel, gugu;
	vector<int>::iterator comeco, fim, parada;
	
	while(cin >> n){
	
		for(i = 0; i < n; i++){
			cin >> aux;
			tarefas.push_back(aux);
		}
		comeco = tarefas.begin();
		fim = tarefas.end();
		fim--;
		
		rangel = *comeco;
		gugu = *fim;
		while (comeco != parada){
			
			if (rangel < gugu){
				comeco++;
				rangel += *comeco;
				
			} else {
				fim--;
				gugu += *fim;
			}
			parada = fim;
			parada--;
		}
		
		cout << abs(rangel - gugu) << endl;
		tarefas.clear();
	}
	return 0;
}
