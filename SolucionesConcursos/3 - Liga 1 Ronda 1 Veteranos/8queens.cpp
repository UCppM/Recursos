#include <bits/stdc++.h>
using namespace std;

/*
    En este problema solamente contamos que haya exactamente 8 reinas
    y vamos viendo que ninguna se coloca en la columna, fila y diagonales
    donde ya hemos colocado las reinas anteriores
*/

#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<char>> tablero(8, vector<char>(8));

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> tablero[i][j];
        }
    }

    vector<int> cols(8, 0);
    vector<int> row(8, 0);
    
    // Se puede ajustar mas pero para asegurar ponemos diagonales de sobra
    vector<int> diagonal1(40, 0);
    vector<int> diagonal2(40, 0);

    bool posible = true;
    int queens = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char c = tablero[i][j];
            if(c == '*') {
                // Si se repite alguna reina no seguimos comprobando
                if(row[j] || cols[i] || diagonal1[i + j] || diagonal2[i - j + 20]) {
                    posible = false;
                    goto next;
                }
                diagonal2[i - j + 20]++;
                diagonal1[i + j]++;
                queens++;
                cols[i]++;
                row[j]++;
                
            }
        }
    }
    next:

    posible = posible && (queens == 8);
    if(posible) cout << "valid" << endl;
    else cout << "invalid" << endl;
}
