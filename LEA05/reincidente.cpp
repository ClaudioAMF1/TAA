#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string nome;
    int artigo;
    map<string, int> ficha;
    
    cin >> nome;
    cin >> artigo;
    
    while (nome != "fim" || artigo != 0) {
        if (ficha.count(nome) == 0) {
            cout << nome << " eh reu primario" << endl;
            ficha[nome] = 0;
        } else {
            cout << nome << " eh reincidente com " << ficha[nome] << " crime(s)" << endl;
        }
        
        ficha[nome]++;
        cin >> nome;
        cin >> artigo;
    }
    
    return 0;
}
