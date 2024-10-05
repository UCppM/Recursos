#include <bits/stdc++.h>
using namespace std;

/*
    En este problema nos tenemos que fijar que para
    minimizar el esfuerzo tenemos que siempre bajar
    cuando haya un desnivel, entonces solo tenemos que calcular
    la diferencia entre peldaños con cuidado.

    Hay que calcular la diferencia entre el ultimo peldaño y 0.
    Siempre a la diferencia le restamos 1 ya que se puede pasar
    de 3 -> 2 sin esfuerzo, pero hay que tener cuidado de no 
    restarle cuando los dos peldaños son iguales.
*/

int main() {
    // Numero de escaleras
    int n;
    cin >> n;


    // Primer peldaño 
    int a;
    cin >> a;

    // Procesamos todos los peldaños
    int solucion = 0;
    for(int i = 1; i < n; i++) {
        int b;
        cin >> b;

        // Calculamos la diferencia entre dos peldaños consecutivos y le restamos 1 si la altura es distinta
        solucion += a - b;
        if(a != b) solucion--;

        // Cambiamos del peldaño 
        a = b;
    }

    // Hay que llegar hasta el cero por lo que tenemos esto en cuenta
    if(a != 0) solucion += a - 1;

    // Imprimimos la solución
    cout << solucion << "\n";
}
