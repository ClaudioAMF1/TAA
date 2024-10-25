#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    vector<pair<string, string>> duelos(T);
    for (auto &d : duelos) {
        cin >> d.first >> d.second;
    }
    
    for (const auto &duelo : duelos) {
        set<char> cartasComuns;
        vector<bool> encontradas(128, false);
        
        for (char c : duelo.first) {
            encontradas[c] = true;
        }
        
        for (char c : duelo.second) {
            if (encontradas[c]) {
                cartasComuns.insert(c);
            }
        }
        
        if (cartasComuns.empty()) {
            cout << "Baralhos prontos para o duelo" << endl;
        } else {
            string resultado;
            for (char c : cartasComuns) {
                resultado += c;
            }
            cout << resultado << endl;
        }
    }
    
    return 0;
}
