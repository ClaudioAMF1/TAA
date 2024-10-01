#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool comparar(const string &a, const string &b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}
 
int main() {
    int N;
    cin >> N;
    vector<string> livros(N);
 
    for (int i = 0; i < N; ++i) {
        cin >> livros[i];
    }
 
    sort(livros.begin(), livros.end(), comparar);
 
    for (const auto &livro : livros) {
        cout << livro << endl;
    }
 
    return 0;
}
