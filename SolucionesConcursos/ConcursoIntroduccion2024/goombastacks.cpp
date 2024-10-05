#include <bits/stdc++.h>
using namespace std;

/*
    En este problema tenemos que ver si podemos
    superar todas las salas de uno en uno.

    Vamos a suponer que es posible pasar y procesamos
    cada sala comparando que la suma acumulada de todos
    los goombas es mayor o igual a los goombas requeridos
    en esa habitacion si esto no es posible paramos el 
    bucle e imprimimos la respuesta.

    OJO!!!: En este caso podemos parar el bucle y no leer toda la entrada
    sin problemas ya que solo hay un caso de prueba por ejecucion del programa.
    En otros problemas tenemos que asegurarnos de leer toda la entrada para 
    pasar al siguiente caso de prueba.
*/

int main() {
    // Leemos el numero salas
    int n;
    cin >> n;

    bool posible = true;
    int numeroGumbasTotal = 0;

    // Procesamos cada sala
    for(int i = 0; i < n && posible; i++) {
        // Leemos cada sala
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