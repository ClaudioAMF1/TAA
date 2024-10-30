#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Formulario {
    string nome;
    string brindes[3];
};

bool verificaBrinde(const Formulario& form, const string& brinde) {
    return (form.brindes[0] == brinde || form.brindes[1] == brinde || form.brindes[2] == brinde);
}

Formulario* buscaUltimoFormulario(vector<Formulario>& forms, const string& nome) {
    for (int i = forms.size() - 1; i >= 0; i--) {
        if (forms[i].nome == nome) {
            return &forms[i];
        }
    }
    return nullptr;
}

void processaFeedback(vector<Formulario>& forms, const string& nome, const string& brinde) {
    Formulario* form = buscaUltimoFormulario(forms, nome);
    
    if (!form) {
        cout << nome << " queria ganhar qualquer coisa e ganhou " << brinde << "!\n";
        return;
    }
    
    if (verificaBrinde(*form, brinde)) {
        cout << nome << " conseguiu ganhar " << brinde << "!\n";
    } else {
        cout << nome << " infelizmente ganhou " << brinde << "...\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p, s;
    cin >> p >> s;
    
    vector<Formulario> formularios;
    formularios.reserve(p);
    
    while (p--) {
        Formulario f;
        cin >> f.nome >> f.brindes[0] >> f.brindes[1] >> f.brindes[2];
        formularios.push_back(f);
    }
    
    string nome, brinde;
    while (s--) {
        cin >> nome >> brinde;
        processaFeedback(formularios, nome, brinde);
    }
    
    return 0;
}