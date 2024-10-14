#include <iostream>
using namespace std;

/*
    En este problema vamos tenemos que calcular el capicua mas proximo
    para ello podemos fijarnos que el podemos ir calculando la distancia desde
    los bordes del numero hasta las cifras del centro de la siguiente manera
    
                   1   5                  2 5
                   |   |                  | |
    12345       -> 12351             ->  12421 -> Es capicua
    Diferencias -> 5 + 6 = 1 mod(10) -> 5 + 7 = 2 mod(10)
    Distancia   -> 6 * 1 = 6         -> 7 * 10 = 70
    Total 70 + 6 = 76

    Existen varias maneras de hacer este problema si te ocurre otra mejor no dudes en comentarla
*/

// Potencias de un numero
int power(int base, int exponente) {
    int res = 1;
    for(int i = 0; i < exponente; i++) res *= base;
    return res;
}

// Devuelve el numero en la posicion i empezando por la derecha
int digito(int n, int i) {
    return n / power(10, i) % 10; 
}

int main()  {
    int casos;
    cin >> casos;

    for(int i = 0; i < casos; i++) {
        int n;
        cin >> n;
        // sumamos uno para el caso de que el numero sea capicua
        n++;
        // Leemos como un string para ver el numero de cifras del numero. Se puede calcular de otras maneras
        string numeroString = to_string(n);

        // La distancia minima es 1, es decir que el siguiente numero sea capicua
        int distancia = 1;

        // Este algoritmo comprueba si la i-esima cifra a la derecha e izquierda son iguales hasta llegar a la del
        // centro, si no son le suma 1 a la de la derecha y actualiza la distancia de manera acorde hasta que lo sean
        for(int i = 0; i <= numeroString.size() / 2; i++) {
            while (digito(n, numeroString.size() - 1 - i) != digito(n, i)) {
                distancia += power(10, i);
                n += power(10, i);
            }
        }
        cout << distancia << endl;
    }    
}