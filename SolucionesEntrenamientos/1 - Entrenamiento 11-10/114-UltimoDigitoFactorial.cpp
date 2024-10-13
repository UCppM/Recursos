#include <iostream>
using namespace std;

/*
    Si calculamos el factorial de los primeros numeros es facil ver un patrón
    1! = 1 = 1
    2! = 2 * 1 = 2
    3! = 3 * 2 = 6
    4! = 4 * 3 * 2 = 24
    5! = 5 * 4 * 3 * 2 = 120
    6! = 720
    7! = 5040

    Si n es menor que 5 podemos saber el ultimo digito calculando el factorial y sacando el resto
    Si n es mayor o igual que 5 tenemos un 0 en el ultimo digito por lo tanto el resto de ultimos digitos 
    seran 0 ya que n * 0 = 0 para todo n
*/

// Esto es una funcion. Es un trozo de codigo reutilizable al que podemos llamar que recibe o no unos parametros
// y puede o no devolver un resultado
int factorial(int n) {
    int res = 1;
    for(int i = n; i > 1; i--) res * i;
    return res;
}

/*
    Esta es la version recursiva de la misma funcion que se aproxima mas a la definicion matematica del factorial

                   { factorial(n - 1) * n, si n >= 1
    factorial(n) = {
                   { 1, si n = 1

int factorial(int n) {
    if(n <= 1) return 1;
    else return factorial(n - 1) * n;
}
*/

int main()  {
    // Leemos el numero de casos
    int casos;
    cin >> casos;

    // Procesamos cada caso
    for(int i = 0; i < casos; i++) {
        // Leemos la entrada de casa caso
        int n;
        cin >> n;

        // Dividimos los casos
        if(n >= 5) {
            cout << "0\n";
        } else {
            cout << factorial(n) % 10 << "\n";
        }
    }
}