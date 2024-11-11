#include <iostream>
#include <vector>

using namespace std;

/*
Si hay mas de una solucion decimos que es ambigup y en caso contrario
sacamos el indice del identificado.

Empezamos leyendo la matriz. Tras eso leemos las 'q' preguntas, y en caso
de que alguna no sea correcta ponemos esa fila a falso (no puede ser nuestra respuesta).
*/

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];
    
    vector<bool> valid(n, true);

    for(int _ = 0; _ < q; _++){
        int col; cin >> col; col--;
        char c; cin >> c;
        for(int i = 0; i < n; i++) {
            if(mat[i][col] != c) valid[i] = false;
        }
    }

    int sol, sols = 0;
    for(int i = 0; i < n; i++){
        if(valid[i]) {
            sols++;
            sol = i;
        }
    }

    if(sols == 1) cout << "unique" << endl << sol + 1 << endl;
    else cout << "ambiguous" << endl << sols << endl;
}
