#include <bits/stdc++.h>
using namespace std;

/*
    En este problema solamente tenemos que ordenar los pianos de tal manera
    que procesemos los pianos que mas tarde acaben primero. Si acaban el mismo tiempo
    procesamos primero el que menos margen nos de.

    Para probar la condicion del fin de semana simplemente hacemos dos pasadas al algoritmo
    teniendo en cuenta los findes de semana o no
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>

bool cmp(pii a, pii b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int m, n;
        cin >> m >> n;
        n /= 2;
        vector<pii> piano(m);
        vector<int>d(101, 0);
        
        for(int i = 0; i < m; i++) {
            cin >> piano[i].first >> piano[i].second;
        }

        sort(piano.begin(), piano.end(), cmp);

        bool posible = true;
        for(auto [l, r] : piano) {
            int i = r;
            for(; i >= l; i--) {
                if(i % 7 == 0 || i % 7 == 6) continue;
                if(d[i] < n) {
                    d[i]++;
                    break;
                }
            }
            if(i < l) {
                posible = false;
                break;
            }
        }

        if(posible) {
            cout << "fine\n";
        } else {
            posible = true;
            d = vector<int>(101, 0);
            for(auto [l, r] : piano) {
                int i = r;
                for(; i >= l; i--) {
                    if(d[i] < n) {
                        d[i]++;
                        break;
                    }
                }
                if(i < l) {
                    posible = false;
                    break;
                }
            }

            if(posible) {
                cout << "weekend work\n";
            } else {
                cout << "serious trouble\n";
            }
        }
    }
}
