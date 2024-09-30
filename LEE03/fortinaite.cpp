#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Jogador {
    string nome;
    int minutos;
    int segundos;
};

bool comparar(const Jogador& a, const Jogador& b) {
    if (a.minutos != b.minutos) 
        return a.minutos > b.minutos;
    if (a.segundos != b.segundos)
        return a.segundos > b.segundos;
    return a.nome < b.nome;
}

int main() {
    int J;
    cin >> J;
    vector<Jogador> jogadores(J);

    for (int i = 0; i < J; ++i) {
        char separador;
        cin >> jogadores[i].nome >> jogadores[i].minutos >> separador >> jogadores[i].segundos;
    }

    sort(jogadores.begin(), jogadores.end(), comparar);

    for (int i = 0; i < J; ++i) {
        cout << i + 1 << ". "
             << (jogadores[i].minutos < 10 ? "0" : "") << jogadores[i].minutos << ":"
             << (jogadores[i].segundos < 10 ? "0" : "") << jogadores[i].segundos
             << " - " << jogadores[i].nome << endl;
    }

    return 0;
}
