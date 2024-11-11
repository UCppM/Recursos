#include <iostream>
#include <vector>

using namespace std;

/*
Dada una matriz 2x2 calcular su inversa

(a  b)
(c  d)

Guardamos la matriz en un vector matrix de cuatro elementos
y usamos la conocida formula de la matriz inversa quedándonos

( d/det    -b/det)
(-c/det     a/det) 
*/

int main(){
	int test_number = 1;
	while(true){
		vector<int> matrix(4);
		for(int j = 0; j < 4; j++) cin >> matrix[j];
		if(!cin) break; // No puede leer mas casos, nos salimos del bucle
		

		int determinante = matrix[0]*matrix[3] - matrix[1]*matrix[2];

		cout << "Case " << test_number << ":" << endl;
		cout << matrix[3]/determinante << " " << -matrix[1]/determinante << endl;
		cout << -matrix[2]/determinante << " " << matrix[0] /determinante << endl;

		test_number++;
	}
}
