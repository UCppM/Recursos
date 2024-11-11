#include <bits/stdc++.h>
using namespace std;

/*
    En este problema dado un numero tenemos que devolver el numero dividido entre 5 al alza
*/

int main() {
    int n; 
    cin >> n;
    // Existen varias maneras de redondear al alza una division de un numero a entre otro numero d
    // (a + d - 1) / d
    // a / d + (a % d != 0)
    cout << (n + 4) / 5 << '\n';
    return 0;
}