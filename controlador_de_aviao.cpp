#include <bits/stdc++.h>
#include <string>

using namespace std;

int verifica_direcao(string aviao){
    if (aviao == "-1")
        return -1;
    if (aviao == "-2")
        return -2;
    if (aviao == "-3")
        return -3;
    if (aviao == "-4")
        return -4;
    return 0;
}

int main(){
	int direcao;
	queue<string> oeste, norte, sul, leste;
	string aviao;
    char espaco = '\0';
	
	cin >> direcao;
	while(direcao != 0){
		if (direcao == -1){
			cin >> aviao;
			while(aviao != "-1" && aviao != "-3" && aviao != "-2" && aviao != "-4" && aviao != "0"){
				oeste.push(aviao);
				cin >> aviao;
			}
			direcao = verifica_direcao(aviao);
		}
		
		if (direcao == -3){
			cin >> aviao;
			while(aviao != "-1" && aviao != "-3" && aviao != "-2" && aviao != "-4" && aviao != "0"){
				norte.push(aviao);
				cin >> aviao;
			}
			direcao = verifica_direcao(aviao);
		}
		
		if (direcao == -2) {
			cin >> aviao;
			while(aviao != "-1" && aviao != "-3" && aviao != "-2" && aviao != "-4" && aviao != "0"){
				sul.push(aviao);
				cin >> aviao;
			}
			direcao = verifica_direcao(aviao);
		}
		
		if (direcao == -4){
			cin >> aviao;
			while(aviao != "-1" && aviao != "-3" && aviao != "-2" && aviao != "-4" && aviao != "0"){
				leste.push(aviao);
				cin >> aviao;
			}
			direcao = verifica_direcao(aviao);
		}
	}
	
    if (!oeste.empty()){
        aviao = oeste.front();
        oeste.pop();
        cout << aviao;	
        espaco = ' ';
    }
    if (!norte.empty()){
        aviao = norte.front();
        norte.pop();
        cout << espaco << aviao;
        espaco = ' ';	
    }
    if (!sul.empty()){
        aviao = sul.front();
        sul.pop();
        cout << espaco << aviao;	
        espaco = ' ';
    }	
    if (!leste.empty()){
        aviao = leste.front();	
        leste.pop();
        cout << espaco << aviao;
        espaco = ' ';
    }

	while(!oeste.empty() || !norte.empty() || !sul.empty() || !leste.empty()){
		if (!oeste.empty()){
			aviao =  oeste.front();
            oeste.pop();
            cout << " " << aviao;
        }	
		if (!norte.empty()){
			aviao = norte.front();
            norte.pop();
            cout << " " << aviao;	
        }
		if (!sul.empty()){
			aviao = sul.front();
            sul.pop();
            cout << " " << aviao;
        }	
		if (!leste.empty()){
			aviao = leste.front();	
            leste.pop();
            cout << " " << aviao;
        }	
	}
	if (espaco == ' ')
    {
        cout << "\n"; 
    }
    
	return 0;
}