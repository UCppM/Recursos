#include <bits/stdc++.h>
using namespace std;

/*
    En este problema tenemos que ver si podemos
    superar todas las salas de uno en uno.

    Vamos a suponer que es posible pasar 
*/

int main() {
    // Leemos el numero salas
    int n;
    cin >> n;

    bool posible = true;
    int numeroGumbasTotal = 0;

    // Procesamos cada sala
    for(int i = 0; i < n; i++) {
        int numeroGumbasSala;
        int numeroGumbasRequeridos;
    
        cin >> numeroGumbasSala >> numeroGumbasRequeridos;
        // Calculamos el numero total de gombas
        numeroGumbasTotal += numeroGumbasSala;

        // Vemos si podemos avanzar a la siguiente sala y nos lo guardamos si no podemos
        if(numeroGumbasTotal < numeroGumbasRequeridos) {
            posible = false;
        }
    }

    // Imprimimos la salida
    if(posible) cout << "possible\n";
    else cout << "impossible\n";
}