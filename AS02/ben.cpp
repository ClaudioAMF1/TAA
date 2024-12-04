#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> grafo;
vector<int> distanciaBen;
vector<int> distanciaAnimal;
 
void bfs (int inicio, vector<int>& distancias, int total) {
    queue<int> fila;
    distancias.assign(total + 1, INT_MAX);
 
    distancias[inicio] = 0;
    fila.push(inicio);
 
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
 
        for (int proximo : grafo[atual]) {
            if (distancias[proximo] == INT_MAX) {
                distancias[proximo] = distancias[atual] + 1;
                fila.push(proximo);
            }
        }
    }
}
 
int main() {
    int vertices, arestas;
    cin >> vertices >> arestas;
 
    grafo.resize(vertices + 1);
 
    while (arestas--) {
        int x, y;
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
 
    int posBen, posAnimal, posSaida;
    cin >> posBen >> posAnimal >> posSaida;
 
    bfs(posBen, distanciaBen, vertices);
    bfs(posAnimal, distanciaAnimal, vertices);
 
    int distBen = distanciaBen[posSaida];
    int distAnimal = distanciaAnimal[posSaida];
 
    cout << (distBen < distAnimal ? "FUGA" : "EMBATE") << endl;
 
    return 0;
}
