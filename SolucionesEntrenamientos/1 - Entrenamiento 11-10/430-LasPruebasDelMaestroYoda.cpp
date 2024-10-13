#include <iostream>
using namespace std;

/*
    En este problema tenemos que irnos guardando el ultimo dia es decir el primer dia
    que podemos hacer una prueba teniendo en cuenta las anteriores
*/

int main()  {
    int numeroPruebas;
    cin >> numeroPruebas;
    while (numeroPruebas != 0) {
        int ultimoDia = 0;
        
        // Procesamos cada dia
        for(int i = 0; i < numeroPruebas; i++) {
            int primerDia, siguiente;
            cin >> primerDia >> siguiente;

            // Si siguiente dia al ultimo es el dia de la prueba o es anterior a la prueba entonces
            // el ultimo dia el primer dia de la prueba
            if(primerDia >= ultimoDia + 1) {
                ultimoDia = primerDia;
            } else {
                // Vamos a aproximar la diferencia de dias al multiplo mayor o igual mas cercano de siguiente
                int diferenciaDias = ultimoDia - primerDia + 1;
                /*
                    La division de enteros aproxima a la baja entonces lo que vamos a hacer el sumarle previamente
                    siguiente - 1 de esta manera obtenemos la division aproximada a la alta y solo tenemos
                    que multiplicar por siguiente para obtener el primer multiplo mayor o igual
                */
                int multiplo = (diferenciaDias + siguiente - 1) / siguiente * siguiente;
                ultimoDia = primerDia + multiplo;
            }
        }

        cout << ultimoDia << endl;
        cin >> numeroPruebas;
    }
}