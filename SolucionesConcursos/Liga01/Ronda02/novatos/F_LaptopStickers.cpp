#include <iostream>
#include <vector>

using namespace std;

/*
El problema se resume en ir simulando como podríamos las pegatinas
en nuestro "portatil" (nuestra matriz en este caso)
*/

int main() {
    int l, h, k;
    cin >> l >> h >> k;
    vector<vector<char>> matrix(h, vector<char>(l, '_')); // creamos una matriz de tamaño hxl y la rellenamos de '_'
    for(int _ = 0; _ < k; _++){
        char c = 'a' + _;
        int dj, di, j, i;

	cin >> dj >> di >> j >> i;

        for(int cur_i = 0; cur_i < di && cur_i + i < h; cur_i++) {
            for(int cur_j = 0; cur_j < dj && cur_j + j < l; cur_j++) {
                matrix[i + cur_i][j + cur_j] = c;
            }
        }
    }
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < l; j++)
		cout << matrix[i][j];
	cout << endl;
    }
    return 0;
}
