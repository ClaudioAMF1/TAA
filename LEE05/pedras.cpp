#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int caso = 0; caso < T; caso++) {
        string catalogo, pedras;
        cin >> catalogo >> pedras;
        
        vector<bool> disponivel(128, false);
        for (char c : catalogo) {
            disponivel[c] = true;
        }
        
        int negociaveis = 0;
        for (char p : pedras) {
            if (disponivel[p]) {
                negociaveis++;
            }
        }
        
        cout << "Contem " << negociaveis << " pedras negociaveis" << endl;
    }
    
    return 0;
}