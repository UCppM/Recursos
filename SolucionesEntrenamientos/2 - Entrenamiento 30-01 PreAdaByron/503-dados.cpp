#include <bits/stdc++.h>
using namespace std;

/*
    El problema se puede resolver en O(n^2) de manera trivial.
    Sin embargo tambien nos podemos fijar que siempre
    los números en el intervalo [min(x, y) + 1, max(x, y) + 1] son
    los que tienen la mayor probabilidad, donde
    x e y son el numero de caras de los daos. 
*/

void resolverCaso() {
    int a, b;
    cin >> a >> b;
    a++; b++;
    for(int i = min(a, b); i < max(a, b); i++) cout << i << " ";
    cout << max(a,b) << endl;
}

int main() {
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) resolverCaso();    
}
