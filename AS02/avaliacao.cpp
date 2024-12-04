#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, K;
    cin >> N >> K;
 
    vector<int> avaliacoes;
    multiset<int> melhores;
 
    for (int i = 0; i < N; ++i) {
        int avaliacao;
        cin >> avaliacao;
 
        avaliacoes.push_back(avaliacao);
        melhores.insert(avaliacao);
 
        if (melhores.size() > K) {
            melhores.erase(melhores.begin());
        }
 
        double soma = 0.0;
        for (int val : melhores) {
            soma += val;
        }
 
        cout << fixed << setprecision(1) << soma / K << endl;
    }
 
    return 0;
}
