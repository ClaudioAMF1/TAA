#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int qtd;
    cin >> qtd;
    
    while (qtd--) {
        string palavra1, palavra2;
        cin >> palavra1 >> palavra2;
        
        if (palavra1.length() != palavra2.length()) {
            cout << "DIFERENTES" << endl;
            continue;
        }
        
        int letras[26] = {0};
        int tam = palavra1.length();
        
        for (int i = 0; i < tam; i++) {
            letras[palavra1[i] - 'a']++;
            letras[palavra2[i] - 'a']--;
        }
        
        bool diferente = false;
        for (int i = 0; i < 26; i++) {
            if (letras[i] != 0) {
                diferente = true;
                break;
            }
        }
        
        cout << (diferente ? "DIFERENTES" : "ANAGRAMAS") << endl;
    }
    
    return 0;
}