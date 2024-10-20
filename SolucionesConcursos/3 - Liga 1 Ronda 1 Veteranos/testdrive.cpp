#include <bits/stdc++.h>
using namespace std;

/*
    Este problema es trivial y se resuelve leyendo el enunciado
    solo hay que tener en cuenta que necesitamos el valor absoluto de las acele raciones
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    int acel1 = abs(b - a);
    int acel2 = abs(c - b);
    if((a > b && c > b) || (a < b && c < b)) cout << "turned\n";
    else if(acel2 > acel1) cout << "accelerated\n";
    else if(acel2 < acel1) cout << "braked\n";
    else cout << "cruised\n";
}
