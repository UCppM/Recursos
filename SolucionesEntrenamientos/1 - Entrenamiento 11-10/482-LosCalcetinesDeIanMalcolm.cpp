#include <iostream>
using namespace std;

/*
    Solo tenemos que calcular el numero de calcetines de cada
    color y responder segun la paridad de ambos numeros

    Lo mas complicado es leer la entrada
*/

bool resolverCaso() {
    char calcetin;
    bool continuar = false;

    cin >> calcetin;
    
    // Si leemos '.' a la primera es que debemos de acabar el programa, no entramos en el condicional
    // y devolvemos false
    if(calcetin != '.') {
        continuar = true;

        int numeroNegros = 0;
        int numeroGris = 0;

        while (calcetin != '.')
        {
            if(calcetin == 'N') {
                numeroNegros++;
            } else { // calcetin == 'G'
                numeroGris++;
            }
            cin >> calcetin;
        }

        // Ninguna calcetin sobra y no los mezclamos
        if(numeroNegros % 2 == 0 && numeroGris % 2 == 0) cout << "EMPAREJADOS" << endl;
        // Sobra un calcetin gris que no podemos emparejar
        else if(numeroNegros % 2 == 0 && numeroGris % 2 == 1) cout << "GRIS SOLITARIO" << endl;
        // Sobra un calcetin negro que no podemos emparejar
        else if(numeroNegros % 2 == 1 && numeroGris % 2 == 0) cout << "NEGRO SOLITARIO" << endl;
        // Sobra un calcetin negro y otro gris que emparejamos
        else cout << "PAREJA MIXTA" << endl;
    }
    
    return continuar;
}

int main()  {
    bool continuar = true;
    while (continuar) {
        // Tratamos cada caso dentro de la funcion hasta que se acaben
        continuar = resolverCaso();
    }
    
}