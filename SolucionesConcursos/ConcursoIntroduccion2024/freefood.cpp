#include <bits/stdc++.h>
using namespace std;

/*
    En este problema nos dan unos intervalos de dias y tenemos
    que ver cuantos dias diferentes se encuentran en los intervalos dados
    para ello vamos a usar un vector

    - Cursillo rapido de vectores-

    Un vector nos permite tener una lista de elementos del mismo tipo a los que podemos
    acceder por indice: miVector[miIndice] es el elemento en la posicion miIndice.
    El primer elemento de vector esta en la posicion 0. Es IMPORTANTE que no accedamos
    a un indice mayor que el tamano del vector es decir que siempre: indice < tamanoVector.

    Para usar un vector es necesario importarlos poniendo '#include <vector>'
    tambien podemos usar '#include <bits/stdc++.h>' que nos incluye los vectores
    y mas cosas que todavia no hemos usado. Esto último solo funciona en Linux, así
    que si usas Windows es posible que te de error al compilar aunque funcione en el
    juez.

    Si no quieres tener que escribir std::vector escribe tambien 'using namespace std;'

    Para crear un vector escribimos vector<tipoElemento> nombreVector(tamanoVector, valorPorDefecto);
        - tipoElemento: Es el tipo de elementos que queremos almacenar por ejemplo int, float, bool...
        - tamanoVector: Es el numero de elemntos que queremos que tenga el vector al principio
        - valorPorDefecto: El valor que tendran todos los elementos al comienzo. No es obligatorio.
                           Podemos escribir solo vector<tipoElemento> nombreVector(tamanoVector)
*/

int main() {
    // Numero de eventos
    int n;
    cin >> n;

    // Vamos a guardar que dias hay comida gratis
    vector<bool> eventos(365, false);

    // Tambien podemos usar un array
    // bool eventos[365];
    // for(int i = 0; i < 365; i++) eventos[i] = false;

    int numeroDiasGratis = 0;

    // Procesamos cada evento
    for(int i = 0; i < n; i++) {
        // Leemos la entrada de cada evento
        int primerDia, ultimoDia;
        cin >> primerDia >> ultimoDia;
        
        // Los vectores y array tienen su primer elemento en la posicion 0, no en la 1
        // Por lo tanto array[0] = Primer elemento del array, en nuestro caso el dia 1 del año
        primerDia--;
        ultimoDia--;

        // Vemos todos los dias en el intervalo para ver que dias no son gratis y cambiarlo
        for(int i = primerDia; i <= ultimoDia; i++) {
            if(eventos[i] == false) { // Esto es equivalente a poner (!eventos[i])
                // Nuevo dia gratis
                eventos[i] = true;
                numeroDiasGratis++;
            }
        }
    }

    // Imprimimos la solucion
    cout << numeroDiasGratis << "\n";
}
