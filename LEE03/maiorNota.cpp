#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int contarNotasMaiores(const vector<int>& listaNotas, int valorCorte) {
    auto it = upper_bound(listaNotas.begin(), listaNotas.end(), valorCorte);
    return distance(it, listaNotas.end());
}

int main() {
    int totalAlunos, totalConsultas;
    cin >> totalAlunos >> totalConsultas;

    vector<int> notasAlunos(totalAlunos);
    for (int i = 0; i < totalAlunos; ++i) {
        cin >> notasAlunos[i];
    }

    vector<string> respostas;
    for (int i = 0; i < totalConsultas; ++i) {
        int corteAtual;
        cin >> corteAtual;

        int resultado = contarNotasMaiores(notasAlunos, corteAtual);
        respostas.push_back(to_string(resultado) + " notas maiores que " + to_string(corteAtual));
    }

    for (const string& resposta : respostas) {
        cout << resposta << endl;
    }

    return 0;
}