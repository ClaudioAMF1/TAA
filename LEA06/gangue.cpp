#include <bits/stdc++.h>
using namespace std;
 
int contaGrupos(vector<vector<int>>& adj, int membros) {
    vector<bool> visitado(membros + 1);
    int grupos = 0;
    
    for (int i = 1; i <= membros; i++) {
        if (!visitado[i]) {
            stack<int> espera;
            espera.push(i);
            visitado[i] = true;
            
            while (!espera.empty()) {
                int atual = espera.top();
                espera.pop();
                
                for (int proximo : adj[atual]) {
                    if (!visitado[proximo]) {
                        visitado[proximo] = true;
                        espera.push(proximo);
                    }
                }
            }
            grupos++;
        }
    }
    
    return grupos;
}
 
int main() {
    int membros, relacoes;
    cin >> membros >> relacoes;
    
    vector<vector<int>> adj(membros + 1);
    
    while (relacoes--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cout << contaGrupos(adj, membros) << " gangue(s) no clube da briga" << endl;
    
    return 0;
}
