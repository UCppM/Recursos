#include <bits/stdc++.h>
using namespace std;

/*
    Para este problema tenemos que hacer una busqueda binaria
    en el espacio de soluciones entre 0 y w.

    Para simular cada posible soluciones usamos un UFDS y tratamos
    de conectar ambas paredes de lado a lado
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>

struct Sphere
{
    double x; double y; double r;
};

struct DSU {
    vi v;
    vi size;
    DSU(int n) : v(n, -1), size(n, 1) {}
    int root(int i) { return v[i] == -1 ? i : v[i] = root(v[i]); }
    bool isSame(int i, int j) { return root(i) == root(j); }
    void join(int i, int j) {
        int ri = root(i);
        int rj = root(j);
        if(size[ri] < size[rj]) swap(ri, rj);
        if(ri != rj) {
            size[ri] += size[rj];
            v[rj] = ri;
        }
    }
};

bool check(vector<Sphere>& v, double w, double dis) {
    DSU dsu(v.size() + 2);

    // for(int i : dsu.v) cout << i << " ";
    // cout << " | " << dis << " " << w << endl;


    for(int i = 0; i < v.size(); i++) {
        auto[x, y, r] = v[i];
        if(x + r + dis>= w) dsu.join(v.size() + 1, i);
        if(x - r - dis <= 0) dsu.join(v.size(), i);
    }

    // for(int i : dsu.v) cout << i << " ";
    // cout << " | " << dis << " " << w << endl;

    for(int i = 0; i < v.size(); i++) {
        auto[x, y, r] = v[i]; 

        for(int j = i + 1; j < v.size(); j++) {
            auto[x1, y1, r1] = v[j];
            double disx = abs(x1 - x); 
            double disy = abs(y1 - y); 
            double disr = r + r1 + dis;
            if(disr * disr >= disx * disx + disy * disy) dsu.join(i, j);
        }
        
    }
    // for(int i : dsu.v) cout << i << " ";
    // cout << " | " << dis << " " << w << endl;
    return !dsu.isSame(v.size(), v.size() + 1);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    while (cases--) {
        int w;
        cin >> w;
        int n;
        cin >> n;
        vector<Sphere> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].x >> v[i].y >> v[i].r;
        }
        double ini = 0;
        double fin = w;
        double mid;
        for(int i = 0; i < 100; i++) {
            mid = (ini + fin) / 2;

            if(check(v, w, mid)) {
                ini = mid;
            } else {
                fin = mid;
            }

        }
        cout << setprecision(6) << fixed << mid / 2 << endl;
    }
    
}
