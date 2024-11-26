#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int vertices, conexoes;
    cin >> vertices >> conexoes;
    
    vector<vector<int>> matriz(vertices, vector<int>(vertices));
    
    while (conexoes--) {
        int a, b;
        cin >> a >> b;
        matriz[a-1][b-1] = 1;
        matriz[b-1][a-1] = 1;
    }
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matriz[i][j];
            if (j < vertices-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
