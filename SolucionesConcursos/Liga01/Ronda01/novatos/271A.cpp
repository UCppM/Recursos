#include <bits/stdc++.h>
using namespace std;

/*
    En este problema simplemente tenemos que ir comprobando
    cada anno siguiente hasta ver que sea bonito
*/

int main() {
    int anno; 
    cin >> anno;
    int a, b, c, d;

    // Comprobamos cada anno siguiente hasta que sea bonito
    do{
        anno++;
        // Extraemos los digitos
        a = anno % 10;
        b = (anno / 10) % 10;
        c = (anno / 100) % 10;
        d = (anno / 1000);
    } while(a == b || a == c || a == d || b == c || b == d || c == d);
    cout << anno << '\n';
    return 0;
}