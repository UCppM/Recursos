#include <bits/stdc++.h>
using namespace std;

/*
    Este problema se resuelve de manera iterativa,
    cogemos una altura y vamos iterando quedandonos con el minimo
    hasta que nos encontramos con un altura mayor o igual en ese caso
    vemos si la diferencia entre la altura anterior y el minimo que hemos guardado es
    mayor al maximo guardado y si es asi es el nuevo maximo, posteriormente
    resetamos el minimo y altura para que sean iguales a la nueva altura

    Esta iteracion la hacemos hacia la derecha y luego hacia la izquierda para 
    comprobar todas las posibilidades
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int maxi = v[0];
    int mini = v[0];

    int res = 0;

    // Iteramos hacia delante
    for(int i = 1; i < n; i++) {
        if(v[i] >= maxi) {
            res = max(maxi - mini, res);
            mini = v[i];
            maxi = v[i];
        } else {
            mini = min(mini, v[i]);
        }
    }

    maxi = v[n - 1];
    mini = v[n - 1];


    // Iteramos hacia detras
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] >= maxi) {
            res = max(maxi - mini, res);
            mini = v[i];
            maxi = v[i];
        } else {
            mini = min(mini, v[i]);
        }
    }

    cout << res << endl;
}
