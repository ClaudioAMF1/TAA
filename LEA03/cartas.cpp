#include <iostream>
#include <deque>
 
using namespace std;
 
int main () {
    int N;
    cin >> N;
 
    deque<int> baralho;
    for (int i = N; i >= 1; i--) {
        baralho.push_back(i);
    }
 
    cout << "Descarte: ";
    bool primeiro = true;
 
    while (baralho.size() > 1) {
        if (!primeiro) {
            cout << ", ";
        }
        cout << baralho.front();
        baralho.pop_front();
        baralho.push_back(baralho.front());
        baralho.pop_front();
        primeiro = false;
    }
 
    cout << endl << "Ultima carta: " << baralho.front() << endl;
 
    return 0;
}
