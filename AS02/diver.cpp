#include <bits/stdc++.h>
using namespace std;
 
vector<vector<pair<int,int>>> grafo;
 
int dijkstra(int inicio, int destino, int total) {
    vector<int> dist(total +1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 
    dist[inicio] = 0;
    pq.push({0, inicio});
 
    while(!pq.empty()) {
        int atual = pq.top().second;
        int d = pq.top().first;
        pq.pop();
 
        if(d > dist[atual]) continue;
 
        for(auto vizinho : grafo[atual]) {
            int proximo = vizinho.first;
            int peso = vizinho.second;
 
            if(dist[atual] + peso < dist[proximo]) {
                dist[proximo] = dist[atual] + peso;
                pq.push({dist[proximo], proximo});
            }
        }
    }
 
    return dist[destino];
}
 
int main() {
    int casas, rotas;
    cin >> casas >> rotas;
 
    grafo.resize(casas + 1);
 
    while(rotas--) {
        int u, v, dist;
        cin >> u >> v >> dist;
        grafo[u].push_back({v, dist});
        grafo[v].push_back({u, dist});
    }
 
    int maior = 0;
    int dist_maior = 0;
 
    for(int i = 2; i <= casas; i ++) {
        int d = dijkstra(1, i, casas);
        if(d == INT_MAX) {
            cout << "Impossivel chegar" << endl;
            return 0;
        }
        if(d > dist_maior) {
            dist_maior = d;
            maior = i;
        }
    }
 
    cout << "Casa mais distante a " << dist_maior << " metros" << endl;
 
    return 0;
}
