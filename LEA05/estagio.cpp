#include <bits/stdc++.h>
using namespace std;
 
string processaArquivo(const string& conteudo) {
    string resultado, unico;
    set<char> letras;
    
    for (char c : conteudo) {
        letras.insert(c);
    }
    
    for (char c : letras) {
        unico += c;
    }
    
    int pos = conteudo.length() - unico.length();
    int match = 0;
    
    for (int i = 0; i <= pos; i++) {
        string subSeq;
        set<char> temp;
        
        for (int j = i; j < i + unico.length(); j++) {
            temp.insert(conteudo[j]);
        }
        
        for (char c : temp) {
            subSeq += c;
        }
        
        if (subSeq == unico) {
            resultado = unico;
            match = i;
            break;
        }
    }
    
    return resultado;
}
 
int main() {
    string entrada;
    cin >> entrada;
    
    cout << processaArquivo(entrada) << endl;
    
    return 0;
}
