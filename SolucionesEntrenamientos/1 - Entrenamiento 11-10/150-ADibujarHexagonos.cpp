#include <iostream>
using namespace std;

/*
    Este es un problema de implementacion. Lo unico que hay que tener cuidado es con los espacios 
*/

// Esta funcion auxiliar nos permite imprimir una linea del hexagono
void imprimirLinea(char caracter, int numeroEspacios, int numeroCaracteres) {
    for(int i = 0; i < numeroEspacios; i++) cout << ' ';
    for(int i = 0; i < numeroCaracteres; i++) cout << caracter;
    cout << endl;
}

int main()  {
    int n;
    char c;
    cin >> n >> c;
    while (n != 0 || c != '0') {
        for(int i = 0; i < n; i++) {
            int espaciosBlancos = n - 1 - i;
            int caracteres = n + 2 * i;
            imprimirLinea(c, espaciosBlancos, caracteres);
        }

        for(int i = n - 2; i >= 0; i--) {
            int espaciosBlancos = n - 1 - i;
            int caracteres = n + 2 * i;
            imprimirLinea(c, espaciosBlancos, caracteres);
        }
        cin >> n >> c;
    }
    
}