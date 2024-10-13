#include <iostream>
using namespace std;

/*
    En este problema tenemos que fijarnos que para obtener un cero tenemos que multiplicar 2 * 5
    es decir un multiplo de 5 por otro de 2, estamos en la funcion factorial por lo tanto tenemos
    un multiplo de 2 cada dos numeros, el problema son los numeros de 5, ya que no hay tantos.

    Tenemos que contar cuantos cincos dividen a nuestro n! para ello dividimos n entre 5
    para ver cuantos numeros entre [1, n] dividen a 5. 

    Hay que fijarse que 25 aporta 2 cincos por lo tanto anade 2 ceros al final por lo tanto
    de n tenemos que calcular el numero de numeros que dividen a 25 y asi sucesivamente 
    con 625 y otras potencias de cinco. No hace falta tener en cuenta que anaden mas ceros ya habremos
    tenido en cuenta el numero de ceros dividir entre las potencias anteriores. Ademas no hace falta
    dividir entre potencias si no solo entre 5 hasta que n sea 0 ya que por ejemplo

    n = 70
    70 / 5 = 7
    70 / 25 = 70 / 5 / 5 = 7 / 5 = 1
    70 / 625 = 70 / 5 = 1 / 5 = 0

    res = 7 + 1 + 0
*/

int main() {
    int casos;
    cin >> casos;

    for(int i = 0; i < casos; i++) {
        int n;
        cin >> n;

        // Acumulamos el numero de 0s
        int suma = 0;
        while (n != 0)
        {
            // Calculamos el numero de multiplos de las potencias de 5
            n /= 5;
            suma += n; 
        }
        
        cout << suma << endl;
    }
}