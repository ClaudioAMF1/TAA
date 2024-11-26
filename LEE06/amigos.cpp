#include <bits/stdc++.h>
using namespace std;
 
int procuraGrupo(vector<int>& grupos, int aluno) {
    if (grupos[aluno] == aluno) {
        return aluno;
    }
    return grupos[aluno] = procuraGrupo(grupos, grupos[aluno]);
}
 
void uneGrupos(vector<int>& grupos, vector<int>& tam, int a, int b) {
    int grupoA = procuraGrupo(grupos, a);
    int grupoB = procuraGrupo(grupos, b);
    
    if (grupoA != grupoB) {
        if (tam[grupoA] < tam[grupoB]) {
            swap(grupoA, grupoB);
        }
        grupos[grupoB] = grupoA;
        tam[grupoA] += tam[grupoB];
    }
}
 
int main() {
    int alunos, ligacoes;
    cin >> alunos >> ligacoes;
    
    vector<int> grupos(alunos), tam(alunos, 1);
    for (int i = 0; i < alunos; i++) {
        grupos[i] = i;
    }
    
    while (ligacoes--) {
        int a, b;
        cin >> a >> b;
        uneGrupos(grupos, tam, a-1, b-1);
    }
    
    int totalGrupos = 0;
    for (int i = 0; i < alunos; i++) {
        if (grupos[i] == i) totalGrupos++;
    }
    
    if (totalGrupos == 1) {
        cout << "Todo mundo eh amigo de todo mundo" << endl;
    } else {
        cout << "Varios grupos de amigos" << endl;
    }
    
    return 0;
}
