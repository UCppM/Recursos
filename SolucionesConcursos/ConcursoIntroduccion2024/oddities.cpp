#include <bits/stdc++.h>
using namespace std;

/*
    En este problema tenemos varios casos de prueba
    donde tenemos que comprobar la paridad de un
    numero dado, para lo que podemos usar el operador %
*/

int main() {

    // Leemos el numero de casos
    int n;
    cin >> n;

    // Ejecutamos cada caso
    for(int caso = 0; caso < n; caso++) {

        // Leemos la entrada
        int x;
        cin >> x;

        // El operador % sirve para calcular
        // el resto de una division.
        bool esPar = (x % 2) == 0; 

        // Imprimimos segun el caso
        if(esPar) {
            cout << x << " is even\n";
        } else {
            cout << x << " is odd\n";
        }
    }
}