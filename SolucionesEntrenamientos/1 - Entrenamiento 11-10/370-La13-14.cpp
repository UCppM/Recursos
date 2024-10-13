#include <iostream>
using namespace std;

/*
    En este problema leemos la entrada y solo nos tenemos que fijar en la paridad del menor
    numero y en que a y b sean consecutivos
*/

int main()  {
    int casos;
    cin >> casos;

    for(int i = 0; i < casos; i++) {
        int a, b;
        char caracterBlanco;
        cin >> a >> caracterBlanco >> b;

        // Existe otra manera de leer la entrada para estos casos importando #include<stdio.h>
        // scanf("%d-%d", &a, &b); %d denota que quiero leer un entero y &a, &b son referencias a a y b
        // es decir la direccion de memoria de a y b lo que permite que las modifiquemos dentro de scanf
        // Para saber mas: https://en.wikipedia.org/wiki/Scanf (Si, tiene un articulo de wikipedia)

        int numeroMenor = min(a, b);

        // Para que exista numeroMenor tiene que ser par y, a y b tiene que ser consecutivos
        // abs(x) es el valor absoluto de x es decir que abs(-1) = abs(1) = 1
        // Entonces si abs(a - b) == 1 -> a + 1 = b o b + 1 = a
        if(numeroMenor % 2 == 0 && abs(a - b) == 1) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }    
}