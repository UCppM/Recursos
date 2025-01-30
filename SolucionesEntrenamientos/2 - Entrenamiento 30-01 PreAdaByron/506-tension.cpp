#include <bits/stdc++.h>
using namespace std;

/*
    Este problema es trivial unicamente tenemos que comprobar que
    la tension minima no sea mayor que la maxima
*/

void resolverCaso() {
    int a, b;
    char c;
    cin >> a >> c >> b;
    if(a >= b) cout << "BIEN\n";
    else cout << "MAL\n";
}

int main() {
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++) resolverCaso();
}
