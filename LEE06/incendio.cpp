#include <bits/stdc++.h>
using namespace std;
 
int buscaMenorCaminho(vector<vector<int>>& adj, int inicio, int fim, int pontos) {
    vector<int> dist(pontos, INT_MAX);
    queue<int> fila;
    
    fila.push(inicio);
    dist[inicio] = 0;
    
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        
        for (int proximo = 0; proximo < pontos; proximo++) {
            if (adj[atual][proximo] && dist[proximo] == INT_MAX) {
                dist[proximo] = dist[atual] + 1;
                fila.push(proximo);
            }
        }
    }
    
    return dist[fim];
}
 
int main() {
    int pontos, corredores;
    cin >> pontos >> corredores;
    
    vector<vector<int>> adj(pontos, vector<int>(pontos));
    
    while (corredores--) {
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }
    
    int agente, extintor, fogo;
    cin >> agente >> extintor >> fogo;
    agente--; extintor--; fogo--;
    
    int caminho1 = buscaMenorCaminho(adj, agente, extintor, pontos);
    int caminho2 = buscaMenorCaminho(adj, extintor, fogo, pontos);
    
    cout << caminho1 + caminho2 << endl;
    
    return 0;
}
