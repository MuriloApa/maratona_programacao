#include <bits/stdc++.h>

using namespace std;

int main() {
	int q, v, y = 0, n = 0, i;
	
	cin >> q;
	for(i = 0; i < q; i++){
		cin >> v;
		if (v == 0)
			y++;
		else
			n++;
	}
	if (y > n)
		cout << "Y\n";
	else
		cout << "N\n";
	return 0;

}
