#include <iostream>
using namespace std;

/*
    En este problema como el numero de casillas es tan 'pequeno' (10^6) podemos calcular
    la suma de uno en uno.

    Existen otros metodos usando una tecnica conocida como exponenciacion binaria y la
    formula de una serie geometrica
*/

int main()  {
    unsigned long long valorInicial, multiplicado, numeroCasillas;
    cin >> valorInicial >> multiplicado >> numeroCasillas;
    while (valorInicial != 0 || multiplicado != 0 || numeroCasillas != 0)  {
        unsigned long long suma = 0;

        // Sumamos el numero de casillas
        for(int i = 0; i < numeroCasillas; i++) {
            suma += valorInicial;
            valorInicial *= multiplicado;
        }

        cout << suma << endl;
        cin >> valorInicial >> multiplicado >> numeroCasillas;
    }
}