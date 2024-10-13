#include <iostream>
using namespace std;

/*
    Calcular el numero parejas de paises distintos es dificil. Sin embargo,
    calcular el numero de parejas totales y el numero de parejas que se pueden formar
    con personas de un mismo pais es mucho mas sencillo:

    El numero de parejas totales o de un mismo pais se puede calcular usando el numero de combinaciones 
    de nºpersonas cogidas de 2 en 2
    n C 2 = n! / (n - 2)! * 2! = n * (n - 1) / 2

    Tambien se puede pensar como conectar a todas las personas con el resto de personas es decir 
    n personas se conectan con n - 1 personas (el resto) y dividimos entre 2 porque cada persona
    cada persona se conectara con otro y esa otra tambien se conectara con esa persona es decir que 
    lo contaremos 2 veces

    Ahora solo queda sumar todas las parejas imposibles, para restarselas a las totales

    NOTA: Aunque el problema diga que el limite de la salida es 10^9 estamos multiplicando numeros
    y es peligroso porque pueden ser mayores que 10^9 en el proceso, por eso es recomendable usar long long
*/

int main()  {
    long long numeroPaises;
    cin >> numeroPaises;
    while (numeroPaises != 0) {
        long long parejasImposibles = 0;
        long long numeroPersonas = 0;
        // Calculamos el numero parejas imposibles, es decir las parejas que se pueden formar con personas del
        // mismo pais
        for(int i = 0; i < numeroPaises; i++) {
            long long personasPais;
            cin >> personasPais;

            numeroPersonas += personasPais;
            parejasImposibles += personasPais * (personasPais - 1) / 2;
        }

        // Calculamos las parejas totales y le restamos las imposibles
        long long parejasTotales = numeroPersonas * (numeroPersonas - 1) / 2;
        long long parejasPosibles = parejasTotales - parejasImposibles;
        cout << parejasPosibles << endl;

        cin >> numeroPaises;
    }
    
}