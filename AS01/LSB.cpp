#include <iostream>
#include <cmath>
using namespace std;
 
int main () {
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        unsigned long long V;
        cin >> V;
 
        if (V == 0) {
            cout << "None" << endl;
        } else {
            int pos = log2(V & -V) + 1;      
            cout << pos << endl;
        }
    }
    return 0;
}
