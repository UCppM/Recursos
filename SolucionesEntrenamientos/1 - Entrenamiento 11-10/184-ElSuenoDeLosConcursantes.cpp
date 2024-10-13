#include <iostream>
#include <iomanip> // Con iomanip tenemos accedo a setfill y setw()
using namespace std;

/*
    En este problema solo tenemos que contar diferencias de horas.
    La forma mas de trabajar con horas es descomponerlas en segundos
    o minutos segun el problema. Entonces lo que hacemos es operar con minutos
    teniendo en cuenta que puede haber un cambio de dia de por medio.
*/

int main()  {
    int noches;
    cin >> noches;

    while (noches != 0) {
        int totalMinutos = 0;
        for(int i = 0; i < noches; i++) {
            int hora0, minuto0, hora1, minuto1;
            char hueco;
            cin >> hora0 >> hueco >> minuto0 >> hueco >> hora1 >> hueco >> minuto1;
            // Se puede hacer
            // scanf("%d:%d-%d:%d", &hora0, &minuto0, &hora1, &minuto1);
            
            // Calculamos las horas en minutos
            minuto0 += 60 * hora0;
            minuto1 += 60 * hora1;

            // Si minuto0 > minuto1 es que ha pasado un dia
            // entonces se lo sumamos a minuto1
            if(minuto0 > minuto1) minuto1 += 24 * 60;
        
            // Calculamos la diferencia y la sumamos al total
            totalMinutos += minuto1 - minuto0;
        }
        
        // Para imprimir el resultado vamos a usar setfill que nos permite
        // cambiar con que caracter vamos a rellenar y setw que nos permite
        // decir que queremos que imprima con un ancho de al menos x lo que le pongamos
        // despues y si no rellene con lo indicado en setfill
        cout << setfill('0') << setw(2) << totalMinutos / 60 << ":" << setw(2) << totalMinutos % 60 << endl;
        cin >> noches;
    }
    
}