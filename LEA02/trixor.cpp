#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> resultados;

    for (int i = 0; i < T; ++i) {
        int A, B, Y;
        cin >> A >> B >> Y;

        int C = A ^ B ^ Y;
        
        if ((A ^ B ^ C) == Y) {
            resultados.push_back(C);
        } else {
            resultados.push_back(-1);
        }
    }

    for (int resultado : resultados) {
        cout << resultado << endl;
    }

    return 0;
}
