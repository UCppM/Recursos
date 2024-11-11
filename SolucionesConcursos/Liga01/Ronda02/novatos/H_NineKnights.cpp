#include <bits/stdc++.h>
using namespace std;

/*
Nos creamos unos arrays auxiliares para simular el movimiento de un caballo.

Ademas nos creamos una funcion 'check' la cual dada una posicion del tablero
se asegura que sea una posicion valida y que haya un caballo en esa posicion.

Finalmente comprobamos que ningun caballo se ataque el uno al otro y que haya
exactamente 9 caballos.
*/

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

bool check(int x, int y, vector<string>& matrix){
	if(x < 0 || x >= 5 || y < 0 || y >= 5) return false;
	if(matrix[x][y] == '.') return false;
	return true;
}

int main(){
	vector<string> matrix(5);
	for(int i = 0; i < 5; i++) cin >> matrix[i];

	bool res = false;
	int cont = 0;

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(matrix[i][j] != '.'){
				cont++;
				for(int k = 0; k < 8; k++)
					if(check(i+dx[k], j+dy[k], matrix))
						res = true;
			}
		}
	}
	if(res || cont != 9)
		cout << "invalid" << endl;
	else 
		cout << "valid" << endl;
}
