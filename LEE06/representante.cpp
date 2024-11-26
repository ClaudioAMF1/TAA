#include <bits/stdc++.h>
using namespace std;
 
int procuraGrupo(vector<int>& grupos, int pos) {
    if (grupos[pos] == pos) return pos;
    return grupos[pos] = procuraGrupo(grupos, grupos[pos]);
}
 
void uneGrupos(vector<int>& grupos, int a, int b) {
    a = procuraGrupo(grupos, a);
    b = procuraGrupo(grupos, b);
    
    if (a != b) {
        grupos[b] = a;
    }
}
 
int main() {
    int alunos, duplas;
    cin >> alunos >> duplas;
    
    vector<int> grupos(alunos);
    vector<int> tamanho(alunos);
    
    for (int i = 0; i < alunos; i++) {
        grupos[i] = i;
        tamanho[i] = 1;
    }
    
    for (int i = 0; i < duplas; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        uneGrupos(grupos, a, b);
    }
    
    map<int, int> freq;
    int maximo = 0;
    
    for (int i = 0; i < alunos; i++) {
        int grupo = procuraGrupo(grupos, i);
        freq[grupo]++;
        maximo = max(maximo, freq[grupo]);
    }
    
    cout << "O grupo mais numeroso tem " << maximo << " aluno(s)" << endl;
    
    return 0;
}
