#include <bits/stdc++.h>
using namespace std;

/*
    En este problema tenemos que ver si una cerilla cabe
    dentro de una caja. Nos podemos fijar que la cerilla
    cabe si su longitud es menor o igual que la diagonal
    de la caja

    Para no usar numeros en coma flotante (a veces tienen 
    problemas de precision) y no hacer raices vamos a 
    comparar los cuadrados de la diagonal y la longitud
    de la cerrilla ya que no nos piden valores concretos
*/

int main() {
    
    // Leemos la entrada
    int n, anchura, altura;
    cin >> n >> anchura >> altura;

    // Podemos calcular el cuadrado de la diagonal
    // con el Teorema de Pitagoras
    int diagonal2 = anchura * anchura + altura * altura;

    // Procesamos cada caso
    for(int i = 0; i < n; i++) {
        int longitudCerilla;
        cin >> longitudCerilla;

        // La cerilla cabe en la caja si es menor o igual que la diagonal de la caja
        // Comparamos los cuadrados de las longitudes para no tener que hacer ninguna
        // raíz cuadrada
        bool cabe = (longitudCerilla * longitudCerilla) <= diagonal2;

        // Imprimimos la salida
        if(cabe) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
}
