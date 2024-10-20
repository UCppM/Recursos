#include <bits/stdc++.h>
using namespace std;

/*
    Para que un torneo sea justo los jugadores que jueguen la final tienen
    que ser los dos mejores por lo tanto. El otro jugador que no pasa
    a la final tiene que ser peor que el mejor jugador del otro lado.
*/

int main() {
    int casos; 
    cin >> casos;

    for(int i = 0; i < casos; i++) {
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        if(min(a, b) < max(c, d) && max(a, b) > min(c, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}