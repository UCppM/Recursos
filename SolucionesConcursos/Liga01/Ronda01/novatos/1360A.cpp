#include <bits/stdc++.h>
using namespace std;

/*
    Para responder a este problema solo tenemos que tener encuenta que existen solo dos opciones

    Posibilidad 1
    XXXXXX  XXXXX
    X1122X  X12 X
    X1122X  X12 X
    X1122X  X12 X
    X    X  XXXXX
    XXXXXX

    Lado max(2 * a, b)

    Posibilidad 2
    XXXXXX  XXXXX
    X111 X  X111X
    X111 X  X222X
    X222 X  X   X
    X222 X  XXXXX
    XXXXXX  

    Lado max(2 * b, a)

    Existe esta otra posibilidad
    XXXXXXX
    X11122X
    X11122X
    X   22X
    X     X
    X     X
    XXXXXXX

    Lado a + b

    Pero se puede demostrar que no es optima:
    El lado es a + b, suponemos que a >= b ( si se da lo contrario la demostracion es igual) 
    entonces podemos expresar a como a = b + x donde x es un numero positivo o igual a 0 cualquiera
    por lo tanto a + b = 2b + x y siempre min(2b + x, 2b) = 2b que ya hemos considerado en casos anteriores.

    Aun asi si no estamos seguros podemos meter esta posibilidad en el codigo ya que no afectara a la solucion
*/

int main() {
    int casos; 
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int a, b; 
        cin >> a >> b;
        // Posibilidad 1
        int lado1 = max(2 * a, b);
        // Posibilidad 2
        int lado2 = max(a, 2 * b);
        int solucion = min({lado1, lado2});
        cout << solucion * solucion << '\n';
    }
    return 0;
}