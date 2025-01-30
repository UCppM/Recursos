#include <bits/stdc++.h>
using namespace std;

/*
    La idea del problema es fijarnos en que podemos dibujar un cono
    no desde la linea sino desde los arboles hacia la linea que reflejen el intervalo
    donde un sensor podria actuar. Entonces para cada arbol obtenemos un intervalo.
    La idea entonces es ver la maxima cantidad de intervalos que se superponen
    como tenemos muchos intervalos que pueden ser muy amplios NO es viable hacer
    un array donde en cada elemento represente el numero de intervalos que contiene

    Como no nos importa identificar cada intervalo sino solamente que haya exista
    podemos simplemente marcar los bordes del intervalo y guardarlos en un array.
    Los bordes que abren el intervalo tienen valor 1 y los que lo cierran -1
    de esta manera si ordenamos los intervalos podemos llevar un contador de los intervalos
    abiertos y guardar el maximo

*/

bool resolverCaso() {
    int n;
    cin >> n;
    if(n == 0) return false;

    vector<pair<int, int>> s(2 * n);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s[2 * i] = {x - y, 1};
        s[2 * i + 1] = {x + y + 1, -1};
    }
    sort(s.begin(), s.end());

    int maximo = 0;
    int actual = 0;
    for(pair<int,int> p : s) {
        actual += p.second;
        maximo = max(maximo, actual);
    }

    cout << maximo << "\n";
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    while(resolverCaso()) {}
}
