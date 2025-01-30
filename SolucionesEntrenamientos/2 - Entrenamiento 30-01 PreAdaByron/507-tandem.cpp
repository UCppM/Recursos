#include <bits/stdc++.h> 

using namespace std;

/*
    Existe la version 'trivial' del algoritmo de
    comprobar todas las parejas en O(nlog(n))
    Sin embargo, podemos mejorar el algoritmo para que tenga
    una complejidad en O(nlog(n))

    La idea es ordenar el vector previamente. Y nos podemos
    fijar que si x e y forman pareja (suponiendo que x<=y)
    todos los numeros que esten a la izquierda de y sirven para
    montar x

    Podemos explotar idea y para cada numero hacer una busqueda binaria en vector
    y hallar el mayor numero que pueda subirse. Hay que tener cuidado y hacer la
    busqueda binaria unicamente a la izquierda de x ya que si no contaremos parejas que
    ya hemos contado antes.

    Es posible mejorar esta parte del algoritmo para que sea lineal teniendo dos punteros
    a cada extremo del array.
    
    Si la suma de valores en los extremos es mayor al peso entonces movemos el puntero
    derecho para reducir el peso. Si el peso es válido entonces todas parejas
    que tienen como primer miembro al puntero del elemento menor y como segundo elemento
    algun miembro entre los dos punteros es valido tambien, sumamos este valor y rodamos 
    el puntero izquierdo
*/

bool resolverCaso() {
    int numero, peso;
  	cin >> numero >> peso;
    if(numero == 0) return false;

    vector<int> v(numero);
    for(int i = 0; i < numero; i++) cin >> v[i];
    
    sort(v.begin(), v.end());
    int i = 0;
    int j = v.size() - 1;

    // Sin el long long da WA porque puede ser muy grande
    long long res = 0;

    while(i < j) {
        if(v[i] + v[j] <= peso) {
            res += j - i;
            i++;
        } else {
            j--;
        }
    }
    cout << res << "\n";
    return true;
}

int main() {
    while (resolverCaso()) {}
}