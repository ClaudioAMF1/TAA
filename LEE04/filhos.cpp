#include <iostream>
#include <vector>
 
using namespace std;
 
int obterFilhoEsquerdo(int no) {
    return 2 * no;
}
 
int obterFilhoDireito(int no) {
    return 2 * no + 1;
}
 
int main() {
    int numNos, numConsultas;
    cin >> numNos >> numConsultas;
 
    vector<int> nos(numNos + 1);
    for (int i = 1; i <= numNos; ++i) {
        cin >> nos[i];
    }
 
    for (int i = 0; i < numConsultas; ++i) {
        int no;
        cin >> no;
 
        if (nos[1] == -1) {
            cout << "NULL" << endl;
            break;
        }
 
        int esquerdo = obterFilhoEsquerdo(no);
        int direito = obterFilhoDireito(no);
 
        if (esquerdo <= numNos && nos[esquerdo] != -1) {
            cout << nos[esquerdo] << " ";
        } else {
            cout << "NULL ";
        }
 
        if (direito <= numNos && nos[direito] != -1) {
            cout << nos[direito] << endl;
        } else {
            cout << "NULL" << endl;
        }
    }
 
    return 0;
}
