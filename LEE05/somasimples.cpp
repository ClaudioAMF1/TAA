#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int qtd;
    long long alvo;
    cin >> qtd >> alvo;
    
    vector<long long> valores(qtd);
    while (qtd--) {
        cin >> valores[valores.size() - qtd - 1];
    }
    
    unordered_set<long long> verificados;
    
    for (auto valor : valores) {
        if (verificados.find(alvo - valor) != verificados.end()) {
            cout << alvo - valor << " " << valor << endl;
            return 0;
        }
        verificados.insert(valor);
    }
    
    cout << "Nao existe" << endl;
    return 0;
}