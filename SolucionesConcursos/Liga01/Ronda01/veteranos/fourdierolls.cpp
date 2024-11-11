#include <bits/stdc++.h>
using namespace std;

/*
    En este problema solo tenemos que ver si ya se repiten o no los elementos
    o no y en base a eso calcular las variaciones con repeticion y sin repeticion
    para calcular todas los posibilidades
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>

int factorial(int n) {
    if(n <= 1) return n;
    else return n * factorial(n - 1);
} 

int potencia(int n, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= n;
    return res;
}

int permutations(int n, int e) {
    return factorial(n) / factorial(n - e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    // Ya se repiten numeros simplemente Variaciones con repeticion de 6 elementos cogidos de 4 - n en 4 - n
    if(n > s.size()) { 
        cout << 0 << " " << potencia(6, 4 - n) << endl; 
    }
    else {
        // Variaciones con repeticion de 6 elementos cogidos de 4 - n en 4 - n
        // El total de posibilidades
        int total = potencia(6, 4 - n);

        // Variaciones de 6 - n elementos cogidos de 4 - n en 4 - n
        // Posibilidades donde no se repiten elementos
        int res = permutations(6 - n, 4 - n);
        cout << res << " " << total - res << endl;
    }

}
