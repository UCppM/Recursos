#include <bits/stdc++.h>
using namespace std;

/*
    El enunciado puede parecer un poco enganoso
    pero solo tenemos que considerar que una subsecuencia de
    longitud 1 tambien es valida  y por lo tanto el elemento mas comun
    de esa subsecuencia es el unico de elemento de la misma.

    Por lo tanto solo tenemos que comprobar que el elemento se encuentre en la lista
*/

int main() {
    int casos; 
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int n, elemento; 
        cin >> n >> elemento;
        bool aparece = false;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;

            // El elemento es el mas comun en la subsecuencia de longitud 1, [i, i + 1)
            if(x == elemento) {
                aparece = true;
            }
        }

        if(aparece) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}