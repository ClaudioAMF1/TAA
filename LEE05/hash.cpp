#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int M, C;
    cin >> M >> C;

    vector<list<int>> hashTable(M);

    for (int i = 0; i < C; ++i) {
        int key;
        cin >> key;
        int index = key % M;
        hashTable[index].push_back(key);
    }

    for (int i = 0; i < M; ++i) {
        cout << i << " -> ";
        for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it) {
            cout << *it << " -> ";
        }
        cout << "\\" << endl;
    }

    return 0;
}