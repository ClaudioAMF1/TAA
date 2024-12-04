
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int qtd;
    cin >> qtd;
 
    while (qtd--) {
        string palavra;
        cin >> palavra;
 
        vector<bool> letras(128, false);
        bool repetiu = false;
 
        for (char c : palavra) {
            if (letras[c]) {
                repetiu = true;
                break;
            }
            letras[c] = true;
        }
 
        cout << (repetiu ? "WEAKORD" : "STRONGRAMA") << endl;
    }
 
    return 0;
}
