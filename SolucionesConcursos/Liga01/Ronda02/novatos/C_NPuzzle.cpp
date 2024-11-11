#include <iostream>
#include <vector>
using namespace std;

/*
La clave en este problema esta en considerar los caracteres como numeros,
hacemos esto restandole a cada caracter la letra 'A' (para mas inforamcion
consultar tabla ASCII https://shorturl.at/eptTd) quedandonos asi algo del estilo
	
	int a = 'C' - 'A';

alli la variable 'a' almacena el 2, pues es la letra numero 2 del abecedario 
(empezando a contar por 0);

Para calcular la posicion en la que deberia ir cada elemento de la matriz equivaldra
a sacar la distancia Manhatan entre su posicion actual y su final. Bastara con sumar
todas estas distancias para sacar la solucion.
*/

int main() {
	int sol = 0;
	vector<string> matrix(4);
	for(int i = 0; i < 4; i++) cin >> matrix[i];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			char c = matrix[i][j];
			if(c == '.') continue;
			int pi = (c - 'A') / 4;
			int pj = (c - 'A') % 4;
			sol += abs(i - pi) + abs(j - pj);
		}
	}

	cout << sol << '\n';
	return 0;
}
