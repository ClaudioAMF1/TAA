#include <iostream>
 
using namespace std;
 
struct No {
    int valor;
    No* esquerdo;
    No* direito;
    
    No(int val) : valor(val), esquerdo(nullptr), direito(nullptr) {}
};
 
No* adicionar(No* raiz, int valor) {
    No* novoNo = new No(valor);
    No* atual = raiz;
    No* anterior = nullptr;
 
    while (atual != nullptr) {
        anterior = atual;
        if (valor < atual->valor) {
            atual = atual->esquerdo;
        } else {
            atual = atual->direito;
        }
    }
 
    if (anterior == nullptr) {
        raiz = novoNo;
    } else if (valor < anterior->valor) {
        anterior->esquerdo = novoNo;
    } else {
        anterior->direito = novoNo;
    }
 
    return raiz;
}
 
void em_ordem(No* raiz) {
    if (raiz != nullptr) {
        em_ordem(raiz->esquerdo);
        cout << raiz->valor << " ";
        em_ordem(raiz->direito);
    }
}
 
void pre_ordem(No* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        pre_ordem(raiz->esquerdo);
        pre_ordem(raiz->direito);
    }
}
 
void pos_ordem(No* raiz) {
    if (raiz != nullptr) {
        pos_ordem(raiz->esquerdo);
        pos_ordem(raiz->direito);
        cout << raiz->valor << " ";
    }
}
 
int main() {
    int N;
    cin >> N;
 
    No* raiz = nullptr;
 
    for (int i = 0; i < N; ++i) {
        int valor;
        cin >> valor;
        raiz = adicionar(raiz, valor);
    }
 
    cout << "In.: ";
    em_ordem(raiz);
    cout << endl;
 
    cout << "Pre: ";
    pre_ordem(raiz);
    cout << endl;
 
    cout << "Pos: ";
    pos_ordem(raiz);
    cout << endl;
 
    return 0;
}
