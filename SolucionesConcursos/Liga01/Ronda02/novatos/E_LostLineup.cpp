#include <iostream>
#include <vector>

using namespace std;

/*
Como Jimmy siempre esta primero en la fila, la posicion
de cada persona sera la distancia a la que estan.
*/

int main() {
	int n; cin >> n;
	vector<int> v(n); v[0] = 1;

	for(int i = 1; i < n; i++){
		int d; cin >> d;
		v[d+1] = i+1;
	}

	for(int i = 0; i < n; i++){
		if(i) cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}
