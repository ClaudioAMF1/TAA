#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tam;
    cin >> tam;
    
    int freq[11] = {0};
    int val;
    
    while(tam--) {
        cin >> val;
        freq[val]++;
    }
    
    for(int i = 0; i <= 10; ++i) {
        while(freq[i]--) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
