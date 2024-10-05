#include <bits/stdc++.h>
using namespace std;

/*
    En este problema solo tenemos que imprimir los 
    numeros entre 1 y N junto con la palabra Abracadabra
*/

int main() {
    
    // Leemos la entrada
    int n;
    cin >> n;

    // Iteramos i con los valores [1,n)
    for(int i = 1; i <= n; i++) {
        cout << i << " Abracadabra\n";
    }

}