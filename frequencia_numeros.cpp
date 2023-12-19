#include <bits/stdc++.h>

using namespace std;

int posicao_vetor(int *vetor, int tamanho, int buscado){
	int i = 0;
	
	while(i < tamanho && vetor[i] != buscado){
		i++;
	}

	if (tamanho == i)
		return -1;
	return i;
}

int main(){
	int n, x, i, pos, topo = 0, j, menor, aux;
	
	cin >> n;
	
	int freq[n], numeros[n];
	
	for(i = 0; i < n; i++){
		cin >> x;
		pos = posicao_vetor(numeros, topo, x);
		
		if (pos == -1){
			numeros[topo] = x;
			freq[topo] = 1;
			topo++;
		} else {
			freq[pos]++;
		}
	}
	
	// Ordenando
	for (i = 1; i < topo; i++){
            menor = numeros[i];
            aux = freq[i];
            j = i;
            while (j > 0 && menor < numeros[j-1])
            {
                numeros[j] = numeros[j-1];
                freq[j] = freq[j-1];
                j--;
            }
            numeros[j] = menor;
            freq[j] = aux;
        }
	
	for (i = 0; i < topo; i++){
		cout << numeros[i] << " aparece " << freq[i] << " vez(es)\n";
	}
	return 0;
}
