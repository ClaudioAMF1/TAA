#include <bits/stdc++.h>
using namespace std;

int main() {
    int qtd;
    long long alvo;
    cin >> qtd >> alvo;
    
    vector<long long> valores(qtd);
    for (int i = 0; i < qtd; i++) {
        cin >> valores[i];
    }
    
    sort(valores.begin(), valores.end());
    
    while (qtd > 2) {
        qtd--;
        long long atual = valores[valores.size() - qtd - 1];
        
        int inicio = valores.size() - qtd;
        int fim = valores.size() - 1;
        
        while (inicio < fim) {
            long long soma = atual + valores[inicio] + valores[fim];
            
            if (soma == alvo) {
                cout << atual << " " << valores[inicio] << " " << valores[fim] << endl;
                return 0;
            }
            
            if (soma < alvo) inicio++;
            else fim--;
        }
    }
    
    cout << "Nao existe" << endl;
    return 0;
}