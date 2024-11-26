
#include <bits/stdc++.h>
using namespace std;
 
int buscaDistancia(int inicio, vector<vector<int>>& grafo, int ilhas) {
    vector<bool> visitado(ilhas);
    vector<int> distancia(ilhas, INT_MAX);
    
    distancia[inicio] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;
    fila.push({0, inicio});
    
    while (!fila.empty()) {
        int atual = fila.top().second;
        fila.pop();
        
        if (visitado[atual]) continue;
        visitado[atual] = true;
        
        for (int proximo = 0; proximo < ilhas; proximo++) {
            if (grafo[atual][proximo] && !visitado[proximo]) {
                if (distancia[proximo] > distancia[atual] + 1) {
                    distancia[proximo] = distancia[atual] + 1;
                    fila.push({distancia[proximo], proximo});
                }
            }
        }
    }
    
    return distancia[ilhas-1];
}
 
int main() {
    int ilhas, pontes;
    cin >> ilhas >> pontes;
    
    vector<vector<int>> grafo(ilhas, vector<int>(ilhas));
    
    for (int i = 0; i < pontes; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        grafo[a][b] = grafo[b][a] = 1;
    }
    
    int resposta = buscaDistancia(0, grafo, ilhas);
    cout << (resposta == INT_MAX ? -1 : resposta) << endl;
    
    return 0;
}
