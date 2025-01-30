#include <bits/stdc++.h>
using namespace std;

/*
    La idea en este problema es crear
    una lista de los zapatos con valor negativo, 
    otra con valor positivo y tambien guardarnos
    para cada posicion si iba un valor positivo o 
    uno negativa. Luego ordenamos las listas zapatos
    positivos y negativos como se indica en el enunciado.
    Y gracias a dos indices y a la lista de posiciones
    asignamos cada zapato en su nuevo lugar
*/

bool resolverCaso() {
    int n;
    cin >> n;
    if(n == 0) return false;

    vector<bool> zapatos(n);
    vector<int> pos, neg;
    pos.reserve(n);
    neg.reserve(n);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x > 0) {
            zapatos[i] = true;
            pos.push_back(x);
        } else {
            neg.push_back(x);           
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    int ip = 0;
    int in = 0;
    for(int i = 0; i < n; i++) {
        if(zapatos[i]) {
            cout << pos[ip++];
        } else {
            cout << neg[in++];
        }

        if(i == n - 1) cout << "\n";
        else cout << " ";
    }

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (resolverCaso()) {}
}
