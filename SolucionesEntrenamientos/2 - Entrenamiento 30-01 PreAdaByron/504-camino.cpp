#include <bits/stdc++.h>
using namespace std;

/*
    Este problema requiere de usar algoritmos mas avanzados.
    Enconcreto algoritmos de grafos.

    Primero usamos busqueda en anchura (BFS) para ver
    el camino que recorre menos puntos.

    Y luego usamos el algoritmo Dijkstra para hallar la menor
    distancia entre los puntos contando tambien con los puntos
    recorridos.

    Mas informacion en:
    https://es.wikipedia.org/wiki/B%C3%BAsqueda_en_anchura
    https://es.wikipedia.org/wiki/Algoritmo_de_Dijkstra
*/

struct Triplet {
    int x, y, z;
};

/*
    Esto es un objeto funcion

    Es como una funcion pero mas potento y por algun motivo C++ no me deja meter
    una funcion normal dentro de una cola de prioridad
*/
struct Compare {
    bool operator()(Triplet& a, Triplet& b) {
        return a.x > b.x || a.x == b.x && a.y > b.y;
    }
};

// Busqueda en anchura
int bfs(vector<vector<pair<int,int>>>& g, int ini, int fin) {
    queue<pair<int, int>> q;
    vector<bool> vis(g.size(), false);

    q.push({ini, 0});
    vis[ini] = true;

    while (!q.empty())
    {
        int id = q.front().first;
        int puntos = q.front().second;
        q.pop();

        if(id == fin) return puntos;

        for(pair<int,int> w : g[id]) {
            int i = w.first;
            if(!vis[i]) {
                vis[i] = true;
                q.push({i, puntos + 1});
            }
        }

    }
    
    return -1;
}

// Algoritmo de Dijkstra
pair<int,int> dijkstra(vector<vector<pair<int,int>>>& g, int ini, int fin) {
    priority_queue<Triplet,vector<Triplet>, Compare> q;
    vector<pair<int, int>> dis(g.size(), {INT_MAX, INT_MAX});

    dis[ini] = {0, 0};
    q.push((Triplet){0, 0, ini});
    while (!q.empty())
    {
        Triplet t = q.top();
        q.pop();

        int distancia = t.x;
        int puntos = t.y;
        int id = t.z;

        for(pair<int, int> p : g[id]) {
            if(dis[p.first].first > distancia + p.second || dis[p.first].first == distancia + p.second && dis[p.first].second > puntos + 1) {
                dis[p.first] = {distancia + p.second, puntos + 1};
                q.push((Triplet){distancia + p.second, puntos + 1, p.first});
            } else {
            }
        }
    }
    
    return dis[fin];
}

bool resolverCaso() {
    int n, c;
    cin >> n >> c;
    if(!cin) return false;

    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < c; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;

        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int ini, fin;
        cin >> ini >> fin;
        ini--; fin--;
        int nBfs = bfs(g, ini, fin);
        pair<int,int> resDjikstra = dijkstra(g, ini, fin);
        int nDjikstra = resDjikstra.second;
        int dis = resDjikstra.first;

        if(nBfs == -1) cout << "SIN CAMINO\n";
        else if(nBfs == nDjikstra) cout << dis << " SI\n";
        else cout << dis << " NO\n";
    }
    cout << "----\n";
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (resolverCaso()){}
}
