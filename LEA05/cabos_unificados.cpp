#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int qtd;
    cin >> qtd;
    
    priority_queue<int, vector<int>, greater<int>> cabos;
    
    for (int i = 0; i < qtd; i++) {
        int tamanho;
        cin >> tamanho;
        cabos.push(tamanho);
    }
    
    long long custoTotal = 0;
    
    while (cabos.size() > 1) {
        int cabo1 = cabos.top(); cabos.pop();
        int cabo2 = cabos.top(); cabos.pop();
        
        int custo = max(cabo1, cabo2);
        int novo = cabo1 + cabo2;
        
        custoTotal += custo;
        cabos.push(novo);
    }
    
    cout << custoTotal << endl;
    
    return 0;
}
