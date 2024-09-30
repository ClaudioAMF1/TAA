#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool verificaExpressao(const string& expressao) {
    stack<char> pilha;
    
    for (char simbolo : expressao) {
        if (simbolo == '(' || simbolo == '[' || simbolo == '{') {
            pilha.push(simbolo);
        } 
        else if (simbolo == ')' || simbolo == ']' || simbolo == '}') {
            if (pilha.empty()) {
                return false;
            }
            
            char topo = pilha.top();
            pilha.pop();
            
            if ((simbolo == ')' && topo != '(') ||
                (simbolo == ']' && topo != '[') ||
                (simbolo == '}' && topo != '{')) {
                return false;
            }
        }
    }
    
    return pilha.empty();
}

int main() {
    string expressao;
    cin >> expressao;
    
    if (verificaExpressao(expressao)) {
        cout << "OK" << endl;
    } else {
        cout << "SyntaxError" << endl;
    }
    
    return 0;
}