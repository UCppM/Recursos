#include <bits/stdc++.h>
using namespace std;

/*
    La idea de este problema es ir colocando cada mejillon en la torre que tenga el tamano
    mas parecido que sea valido de esta manera podemos. Crear un array ordenado donde hacer
    la busqueda en O(log(n)) por medio de busqueda binaria
*/

bool resolverCaso() {
    // Lectura de la entrada
    int nMejillones;
    cin >> nMejillones;

    if(!cin) return false;

    vector<int> torres;

    // Procesamos cada mejillon
    for(int i = 0; i < nMejillones; i++) {
        int mejillon;
        cin >> mejillon;

        // Busqueda binaria del menor elemento mayor que el elemento dado
        int ini = 0;
        int fin = torres.size();
        while (ini < fin)
        {
            int mid = (ini + fin) / 2;
            if(torres[mid] <= mejillon) ini = mid + 1;
            else fin = mid;
        }
        
        // Si el elemento se sale del array lo anadimos en una nueva posicion
        if(ini == torres.size()) torres.push_back(mejillon);
        else torres[ini] = mejillon;
    }

    cout << torres.size() << "\n";

    return true;
}

int main() {
    while (resolverCaso()) {}
}
