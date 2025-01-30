#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    La idea en este problema es hacer una busqueda en el espacio
    de las soluciones, es decir, por medio de la busqueda
    bineria estimar el valor minimo de carga

    La idea es que si tenemos una funcion que actue
    como un oraculo que nos diga si es posible o no llegar al final
    con un nivel de carga X inicial podemos hacer la busqueda binaria

    Para esta funcion magica vamos a hallar si llegar al final
    es posible por medio de programacion dinamica.

    Queremos ir desde la esquina superior izquierda a la inferior derecha
    en el menor numero de casillas moviendonos en un tablero de ajedrez de uno
    en uno sin movimientos diagonales. Por lo que para llegar el numero minimo
    de movimientos se puede observar que solo nos podemos mover hacia la derecha o hacia abajo.
    Sin volvar hacia atrás

    Ahora suponiendo que quiero llegar a la casilla (x, y) sabemos
    que solamente es posible llegar desde arriba (x, y - 1) o desde la izquierda
    (x - 1, y). Esto solo es posible si alguna de las dos casillas es alcanzable
    y si al llegar a la casilla (x, y) en el mejor caso no llego con una bateria 
    menor a 2

    Con un poco de cuidado podemos aplicar programacion dinamica. Esta explicado
    un poco regular si teneis dudas preguntar.
*/

bool valido(int ci, int w, int h, vector<vector<int>>& c) {
    vector<pair<int, bool>> v(w + 1, {-1e9, false});

    v[1] = {ci, true};

    for(int i = 0; i < h; i++) {
        for(int j = 1; j <= w; j++) {
            int m = 0;
            bool valid = false;
            if(v[j].second) { valid = true; m = v[j].first; }
            if(v[j - 1].second) { valid = true; m = max(v[j - 1].first, m); }

            m += c[i][j];
             valid = valid && m >= 2;
            v[j] = {m, valid};
        }
    }

    return v[w].second;
}

bool resolverCaso() {
    int w, h;
    cin >> w >> h;
    if(!cin) return false;
    vector<vector<int>> c(h, vector<int>(w + 1));
    for(int i = 0; i < h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }

    int ini = 2;
    int fin = 1e10;

    while (ini < fin) {
        int mid = (ini + fin) / 2;
        if(valido(mid, w, h, c)) {
            fin = mid;
        } else {
            ini = mid + 1;
        }
    }
    
    cout << ini << '\n';

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (resolverCaso()){}
}