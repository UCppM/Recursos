#include <bits/stdc++.h>
using namespace std;

/*
    Simplemente leyendo el enunciado podemos solucionarlo:-
    - A stair satisfies the condition a < b < c
    - A peak satisfies the condition a < b > c
*/

int main() {
    int casos; 
    cin >> casos;
    for(int i = 0; i < casos; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a < b && b < c) cout << "STAIR\n";
        else if(a < b && b > c) cout << "PEAK\n";
        else cout << "NONE\n";
    }
    return 0;
}