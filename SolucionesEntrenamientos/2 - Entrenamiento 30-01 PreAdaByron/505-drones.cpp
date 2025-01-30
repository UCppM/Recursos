#include <bits/stdc++.h>
using namespace std;

/*
    La idea del problema es usar colas de prioridad. Una para cada tipo de pila
    cada jornada vamos sacando todas las pilas que podamos hasta sacar las
    pilas necesarias para todos los drones. De cada par de pilas
    pueden pasar tres cosas o se descarta la primera pila y la segunda
    que tiene mas bateria sigue sirviendo, lo contrario se descarta la segunda
    o cuidado que si las dos tienen la misma bateria descartamos las dos.
    Estas pilas que no hemos descartado las guardamos en dos vectores auxiliares
    Y al final de la jornada las volvemos a introducir en las colas de prioridad y asi sucesivamente
    hasta que no nos queden pilas. En cada jornada hay que calcular las horas de vuelos totales de todos los
    drones que vamos a guardar en un tercer array y que imprimiremos al final del programa.


    NOTA: Para los que estuvieron creia que este problema se podia resolver con vectores. Lo probe al final y daba TLE
*/

bool resolverCaso() {
    int n, a, b;
    cin >> n >> a >> b;

    if(!cin) return false;

    priority_queue<int> pa;
    priority_queue<int> pb;

    for(int i = 0; i < a; i++) {
        int x;
        cin >> x;
        pa.push(x);
    }

    for(int i = 0; i < b; i++) {
        int x;
        cin >> x;
        pb.push(x);
    }

    vector<int> horas;

    while (!pa.empty() && !pb.empty())
    {
        horas.push_back(0);
        vector<int> ra;
        vector<int> rb;
        
        for(int i = 0; i < n && !pa.empty() && !pb.empty(); i++) {
            int x = pa.top(); pa.pop();
            int y = pb.top(); pb.pop();

            horas.back() += min(x, y);
            if(x > y) {
                ra.push_back(x - y);
            } else if(x < y) {
                rb.push_back(y - x);
            }
        }

        for(int i : ra) pa.push(i);
        for(int i : rb) pb.push(i);
    }
    

    for(int i = 0; i < horas.size(); i++) {
        cout << horas[i];
        if(i !=  horas.size() - 1) cout << " ";
        else cout << "\n";
    }

    return true;
}

int main() {
    while (resolverCaso()) {}
}
