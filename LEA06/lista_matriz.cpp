#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int tamanho;
    cin >> tamanho;
    
    vector<vector<int>> matriz(tamanho, vector<int>(tamanho));
    
    for (int i = 0; i < tamanho; i++) {
        int adj;
        cin >> adj;
        
        while (adj--) {
            int vizinho;
            cin >> vizinho;
            vizinho--;
            matriz[i][vizinho] = 1;
        }
    }
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            cout << matriz[i][j];
            if (j < tamanho - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
