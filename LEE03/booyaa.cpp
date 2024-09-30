#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long F, D;
    cin >> F >> D;

    vector<int> subscricoes(30);
    for (int &s : subscricoes) {
        cin >> s;
    }

    long long totalSeguidores = F;

    for (int dia = 0; dia < D; ++dia) {
        long double soma = 0;
        for (int k = 0; k < 30; ++k) {
            soma += subscricoes[k];
        }

        long long mediaAritmetica = ceil(soma / 30.0);
        totalSeguidores += mediaAritmetica;

        subscricoes.erase(subscricoes.begin());
        subscricoes.push_back(mediaAritmetica);
    }

    cout << totalSeguidores << endl;

    return 0;
}
