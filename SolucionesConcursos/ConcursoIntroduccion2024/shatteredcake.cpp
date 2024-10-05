#include <bits/stdc++.h>
using namespace std;

/*
    Para este problema tenemos que calcular el largo de una tarta
    dada una anchura y los trozos que forman la tarta.

    La primera idea seria de alguna manera colocar los trozos para que
    formen un rectangulo. 
    
    Sin embargo, esto no es necesario ya que con conocer el area total 
    de la tarta podemos calcular la altura. El area total es la suma 
    del area de los trazos.

    longitud = areaTotal / anchura
    longitud = sum(anchuraTrozo * longitudTrozo) / anchura
*/

int main() {

    // Leemos la entrada inicial
    int anchuraTarta;
    int n;
    cin >> anchuraTarta >> n;

    // Vamos a calcular el area total de todos los trozos
    int area = 0;

    // Procesamos cada trozo
    for(int i = 0; i < n; i++) {

        // Leemos entrada
        int ancho, largo;
        cin >> ancho >> largo;

        // Actualizamos el area total
        area += ancho * largo;
    }

    // Teniendo el area total de la tarta y el ancho podemos calcular el alto dividiendo
    int largoTarta = area / anchuraTarta;

    // Imprimimos el resultado
    cout << largoTarta << "\n";
}