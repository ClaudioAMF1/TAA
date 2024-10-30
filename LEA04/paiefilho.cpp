#include <iostream>
#include <vector>

using namespace std;

int pegaPai(int no) {
    return no >> 1;
}

int pegaFilhoEsquerdo(int no) {
    return no << 1;
}

int pegaFilhoDireito(int no) {
    return (no << 1) | 1;
}

void processaConsulta(const vector<int>& arv, int no) {
    if (arv[1] == -1) {
        cout << "NULL\n";
        return;
    }

    if (no == 1) {
        cout << "RAIZ - ";
    } else {
        cout << arv[pegaPai(no)] << " - ";
    }
    
    int esq = pegaFilhoEsquerdo(no);
    int dir = pegaFilhoDireito(no);
    
    cout << (esq < arv.size() && arv[esq] != -1 ? to_string(arv[esq]) : "NULL") << " ";
    cout << (dir < arv.size() && arv[dir] != -1 ? to_string(arv[dir]) : "NULL") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;
    
    vector<int> arv(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arv[i];
    }
    
    while (c--) {
        int consulta;
        cin >> consulta;
        processaConsulta(arv, consulta);
    }
    
    return 0;
}