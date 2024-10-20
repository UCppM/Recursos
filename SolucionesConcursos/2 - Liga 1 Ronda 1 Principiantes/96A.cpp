#include <bits/stdc++.h>
using namespace std;

/*
    En este problema leemos la entrada aunque sean numeros como un
    string para acceder a los indices facilemente y vamos contando
    las ocurrencias de elementos seguidos guardandonos el ultimo caracter
*/

int main() {
    string entrada; 
    cin >> entrada;

    char lastChar = 'a';
    int contador = 0;
    bool peligroso = false;
    for(char c : entrada) {
        if(c == lastChar) contador++;
        else contador = 1;
        
        lastChar = c;
        if(contador == 7) peligroso = true;
    }

    if(peligroso) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}