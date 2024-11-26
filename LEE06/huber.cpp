#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int locais, rotas;
    cin >> locais >> rotas;
    
    vector<vector<pair<int,int>>> grafo(locais);
    
    while (rotas--) {
        int a, b, dist;
        cin >> a >> b >> dist;
        a--; b--;
        grafo[a].push_back({b, dist});
        grafo[b].push_back({a, dist});
    }
    
    vector<int> distancia(locais, INT_MAX);
    distancia[0] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;
    fila.push({0, 0});
    
    while (!fila.empty()) {
        int dist = fila.top().first;
        int atual = fila.top().second;
        fila.pop();
        
        if (dist > distancia[atual]) continue;
        
        for (auto [proximo, peso] : grafo[atual]) {
            int novaDistancia = dist + peso;
            
            if (novaDistancia < distancia[proximo]) {
                distancia[proximo] = novaDistancia;
                fila.push({novaDistancia, proximo});
            }
        }
    }
    
    if (distancia[locais-1] == INT_MAX) {
        cout << "Preso no IDP" << endl;
    } else {
        cout << "Distancia para chegar em casa: " << distancia[locais-1] << endl;
    }
    
    return 0;
}
