#include <bits/stdc++.h>
using namespace std;

/*
    Este problema puede parecer imposible a primera vista pero si pensamos 
    en el numero de slimes como un numero binario es facil ver la respuesta.
    El numero de noches en este problema por lo que nos vamos a olvidarnos de el

    Si tenemos 10 slimes esto es equivalente a 10 = 8 + 2 = 2^3 + 2^1 = 0b1010
    Vamos a ver como hemos llegado hasta el diez:
        - Empezamos teniendo 0 slimes
        - El primer dia el panda suelta un slime, es decir tenemos 1 = 0b1
        - Por la noche este se duplica por lo que obtenemos 2 = 0b10
        - El segundo dia el panda no suelta un slime y acabamos con 4 = 0b10 tras la noche
        - El tercer dia el panda suelta slime y acabamos con 5 = 0b101 lo que pasa a 
          ser 10 = 0b1010 tras la noche
        - Al cuarto dia vemos que hay 10 slimes por tanto la solucion es 2
    Hemos dicho que el numero de noches no importa ya que podemos suponer que todas las noches
    anteriores a las 4 ultimas el panda no estornudo ningun slime.

    Con este ejemplo podemos ver que cada dia que suelta slime se representa por un bit = 1 que cada noche 
    rodamos a la izquierda, entonces solo tenemos que contar el numero de bits = 1 que tiene nuestro numero
    esto lo podemos hacer diviendo el numero entre dos y viendo la paridad hasta que el numero sea cero

    NOTAS:

    El operador & lo podemos aplicar entre dos numeros y equivale a aplicar una operacion AND a cada bit 
    de ambos numeros:     
                                    | A | B | AND | OR | XOR |
                                    |---|---|-----|----|-----|
                                    | 0 | 0 |  0  |  0 |  0  |
    0b1100 & 0b1010 = 0b1000        | 0 | 1 |  0  |  1 |  1  |
      12   &   10   =    8          | 1 | 0 |  0  |  1 |  1  |
                                    | 1 | 1 |  1  |  1 |  0  |
                                    
    De manera existe el operador | que aplica un OR y el operador ^ que aplica un XOR

    El operador >> lo podemos aplicar entre dos numeros y equivale a rodar x bits del primer numero
    a la derecha

    0b1011 >> 2 = 0b10
      11   >> 2 =  2

    Tambien existe el operador << que hace lo mismo pero rondando a la izquierda
*/

int main() {
    // Leemos la entrada
    long long numeroDias, numeroSlime;
    int solucion = 0;
    cin >> numeroDias >> numeroSlime;

    // El numero de dias no es importante para resolver el problema
    // Importante que nuestras variables sean del tipo long long


    // Vamos a calcular el numeros de bits a uno en binario que
    // tiene numeroSlime
    while (numeroSlime != 0) {
        // Vemos el bit mas a la izquierda del numero
        // Tambien podemos usar el operador &: numeroSlime & 1
        int bit = numeroSlime % 2; 

        // Rodamos los bits del numero a la derecha diviendo entre dos
        // Tambien podemos usar el operador >> : numeroSlime >> 1
        numeroSlime = numeroSlime / 2;

        if(bit) solucion++;
    }
    
    // Imprimimos la solucion
    cout << solucion << "\n";
}