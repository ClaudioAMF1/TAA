#include <bits/stdc++.h>
using namespace std;

struct Competidor {
    string nome;
    int poder;
    int indice;
    
    bool operator<(const Competidor& outro) const {
        if (poder == outro.poder) {
            if (nome == outro.nome) {
                return indice < outro.indice;
            }
            return nome < outro.nome;
        }
        return poder < outro.poder;
    }
};

int main() {
    int quantidade;
    cin >> quantidade;
    
    vector<Competidor> inicial(quantidade);
    
    for (int i = 0; i < quantidade; i++) {
        cin >> inicial[i].nome >> inicial[i].poder;
        inicial[i].indice = i;
    }
    
    priority_queue<Competidor> arena(inicial.begin(), inicial.end());
    vector<string> duelos;
    
    while (arena.size() > 1) {
        Competidor c1 = arena.top(); arena.pop();
        Competidor c2 = arena.top(); arena.pop();
        
        string duelo = c1.nome + " (" + to_string(c1.poder) + ") x (" + 
                      to_string(c2.poder) + ") " + c2.nome + " : ";
        
        if (c1.poder == c2.poder) {
            duelos.push_back(duelo + "empate");
            continue;
        }
        
        if (c1.poder > c2.poder) {
            duelos.push_back(duelo + c1.nome + " venceu");
            c1.poder -= c2.poder;
            arena.push(c1);
        } else {
            duelos.push_back(duelo + c2.nome + " venceu");
            c2.poder -= c1.poder;
            arena.push(c2);
        }
    }
    
    if (arena.empty()) {
        duelos.push_back("nenhum vencedor");
    } else {
        Competidor vencedor = arena.top();
        duelos.push_back(vencedor.nome + " venceu com " + to_string(vencedor.poder));
    }
    
    for (const string& duelo : duelos) {
        cout << duelo << endl;
    }
    
    return 0;
}
