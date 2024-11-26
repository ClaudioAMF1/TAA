#include <bits/stdc++.h>
using namespace std;
 
int calculaCaminho(int inicio, int final, vector<vector<int>>& rotas, vector<bool>& bloqueios, bool evitar) {
    queue<int> fila;
    vector<int> distancia(rotas.size(), -1);
    
    fila.push(inicio);
    distancia[inicio] = 0;
    
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        
        for (int proximo = 0; proximo < rotas.size(); proximo++) {
            if (rotas[atual][proximo] && distancia[proximo] == -1) {
                if (evitar && bloqueios[proximo]) continue;
                
                distancia[proximo] = distancia[atual] + 1;
                fila.push(proximo);
            }
        }
    }
    
    return distancia[final];
}
 
int main() {
    int locais, caminhos, cameras;
    cin >> locais >> caminhos >> cameras;
    
    vector<bool> vigiado(locais);
    for (int i = 0; i < cameras; i++) {
        int pos;
        cin >> pos;
        vigiado[pos-1] = true;
    }
    
    vector<vector<int>> rotas(locais, vector<int>(locais));
    while (caminhos--) {
        int a, b;
        cin >> a >> b;
        rotas[a-1][b-1] = rotas[b-1][a-1] = 1;
    }
    
    int inicio, saida, chave;
    cin >> inicio >> saida >> chave;
    inicio--; saida--; chave--;
    
    int rota1 = calculaCaminho(inicio, chave, rotas, vigiado, true);
    int rota2 = rota1 != -1 ? calculaCaminho(chave, inicio, rotas, vigiado, true) : -1;
    int rota3 = calculaCaminho(inicio, saida, rotas, vigiado, false);
    
    if (rota1 == -1 || rota2 == -1 || rota3 == -1) {
        cout << "impossivel fugir" << endl;
    } else {
        cout << rota1 + rota2 << " " << rota3 << endl;
    }
    
    return 0;
}
