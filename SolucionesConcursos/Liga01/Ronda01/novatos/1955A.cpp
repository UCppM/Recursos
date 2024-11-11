#include <bits/stdc++.h>
using namespace std;

/*
    En este problema tenemos dos casos:

    Que la promocion sea mas barata que compras dos yogures (b < 2 * a) o que sea mas cara

    En el primer caso vemos cuantos yogures podemos comprar con la promocion es decir n / 2 * b 
    y si n es impar compramos uno con el precio a

    En el segundo caso todos los yogures los compramos con el precio a es decir n * a
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casos; cin >> casos;
    for(int i = 0; i < casos; i++) {
        int n, a, b; 
        cin >> n >> a >> b;

        // Caso 1: El precio de la promocion es mas barato que compras dos yogures por seperado
        if(b < 2 * a) cout << n / 2 * b + (n % 2) * a << '\n';
        // Caso 2: Es mas barato comprar dos yogures por separado
        else cout << n * a << '\n';
    }
    return 0;
}