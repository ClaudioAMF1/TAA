#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int p, r;
    cin >> p >> r;
    
    vector<int> atual;
    int cadeira;
    
    for (int i = 0; i < p; i++) {
        cin >> cadeira;
        atual.push_back(cadeira);
        sort(atual.begin(), atual.end());
        
        if (r > atual.size()) {
            cout << atual.back() << "\n";
        } else {
            cout << atual[r-1] << "\n";
        }
    }
    
    return 0;
}