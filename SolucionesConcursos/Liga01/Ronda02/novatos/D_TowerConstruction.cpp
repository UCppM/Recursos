#include <iostream>
using namespace std;

/*
Leemos n numeros. En casa de que el elemento actual sea mayor
que el anterior que hemos leido, sumamos 1 a nuestro contador.
*/

int main() {
    int n; cin >> n;
    int act, ant, sol = 1;
    cin >> act;
    for(int i = 1; i < n; i++){
    	ant = act;
        cin >> act;
        if(act > ant) sol++;
    }
    cout << sol << '\n';
    return 0;
}
