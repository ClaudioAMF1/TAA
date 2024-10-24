#include <iostream>
#include <vector>
 
using namespace std;
 
int obterPai(int no) {
    return no >> 1;
}
 
int main() {
    int numNos, numConsultas;
    cin >> numNos >> numConsultas;
 
    vector<int> arvore(numNos + 1);
    for (int i = 1; i <= numNos; ++i) {
        cin >> arvore[i];
    }
 
    for (int i = 0; i < numConsultas; ++i) {
        int consulta;
        cin >> consulta;
 
        if (arvore[1] == -1) {
            cout << "NULL" << endl;
            break;
        }
 
        if (consulta == 1) {
            cout << "RAIZ" << endl;
            continue;
        }
 
        int pai = obterPai(consulta);
 
        if (pai >= 1 && arvore[pai] != -1) {
            cout << arvore[pai] << endl;
        } else {
            cout << "NULL" << endl;
        }
    }
 
    return 0;
}
