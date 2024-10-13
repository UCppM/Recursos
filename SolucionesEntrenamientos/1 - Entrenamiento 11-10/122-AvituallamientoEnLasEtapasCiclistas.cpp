#include <iostream>
using namespace std;

/*
    En este problema una de las cosas mas complicadas es leer la entrada y hay que tener
    cuidado.

    Por otro lado lo unico que hay que hacer es irnos guardando la seccion de mayor
    longitud y la longitud de la seccion plana actual e ir actualizandolos en cada kilometro
*/

int main()  {
    int altura;

    // Leemos la primera altura
    cin >> altura;

    // Seguimos ejecutandos casos de prueba mientras != -1
    while (altura != -1) {
        int longitudActual = 0;
        int longitudMaxima = 0;
        int kilometroMaximo = 0;
        int kilometro = 1;

        // Nos guardamos la altura y leemos la siguiente
        int alturaAnterior = altura;
        cin >> altura;

        // Seguimos procesando el caso hasta que encontremos un -1
        while (altura != -1) {
            // Si el kilometro es llano nos vamos guardando la longitud del segmento plano
            if(altura == alturaAnterior) {
                longitudActual++;

                // Si el segmento es mayor que el que maximo que hemos guardado actualizamos la solucion
                if(longitudActual > longitudMaxima) {
                    kilometroMaximo = kilometro - longitudActual;
                    longitudMaxima = longitudActual;
                }
            } else {
                longitudActual = 0;
            }

            kilometro++;
            alturaAnterior = altura;
            cin >> altura;
        }
        
        if(longitudMaxima == 0) {
            cout << "HOY NO COMEN" << endl;
        } else {
            cout << kilometroMaximo << " " << longitudMaxima << endl;
        }

        // Leemos la altura del siguiente caso
        cin >> altura;
    }
}