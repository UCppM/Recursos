#include <bits/stdc++.h>
using namespace std;

/*
    En este problema solomente tenemos que ver
    si tenemos menos cervezas o menos limonada
    y multiplicar por dos el minimo para obtener
    el shandy que podemos hacer

    Existen la funcion min(int a, int b) y 
    max(int a, int b) que devuelven el minimo y
    maximo entre a y b respectivamente.
*/

int main() {
    // Leemos la entrada
    int cerveza, limonada;
    cin >> cerveza >> limonada;

    // Calculamos el minimo
    int minimo;
    if(cerveza > limonada) {
        minimo = limonada;
    } else {
        minimo = cerveza;
    }
    // Esto es equivalente a: int minimo = min(cerveza, limonada);

    // Imprimimos el resultado
    cout << 2 * minimo << "\n";
}
