#include <iostream>
#include <vector>

using namespace std;

/*
Leemos la matriz y luego iteramos columna a columna
si en la columna hay almenos un '$' sumamos 1 a nuestra
solucion final.
*/

int main() {
	int h, w, sol = 1;
	cin >> h >> w;

	vector<string> mat(h);
	for(int i = 0; i < h; i++) cin >> mat[i];

	for(int i = 0; i < w; i++){
		bool vacia = true;
		for(int j = 0; j < h; j++)
			if(mat[j][i] == '$') vacia = false;
		if(vacia) sol++;
	}

	cout << sol << '\n';
	return 0;
}
