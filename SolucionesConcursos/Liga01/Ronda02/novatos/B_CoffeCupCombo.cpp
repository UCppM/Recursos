#include <iostream>
using namespace std;

/*
Leeremos la secuencia binaria (0s y 1s) que nos dan caracter a caracter.

La variable count lleva la cantidad de cafes que tienes disponibles
(haces refill si te sale un 1) y simplemente vas simulando el día.

La variable sol lleva la cantidad de clases a las que ha podido
ir despierta.
*/

int main() {
	int n; cin >> n;
	int count = 0, sol = 0;
	for(int i = 0; i < n; i++) {
		char c; cin >> c;
		if(c == '1') {
		    sol++;
		    count = 2;
		}
        else if(count > 0) {
		count--;
		sol++;
        }
    }
    cout << sol << '\n';
    return 0;
}
