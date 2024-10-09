#include<bits/stdc++.h>
using namespace std;

int main() {
    int P;
    int A, B;
    queue<int> esq;
    queue<int> dir;

    cin >> P;
    while(P--){
        cin >> A >> B;
        esq.push(A);
        dir.push(B);
    }

    bool continuar = true;
    while(continuar){
        if(esq.empty() && dir.empty()){
            continuar = false;
            break;
        }

        cout << esq.front() << " " << dir.front() << endl;
        esq.pop();
        dir.pop();

        if(esq.empty() && dir.empty()){
            continuar = false;
            break;
        }

        if((esq.front() + dir.front()) == 7) {
            esq.push(esq.front());
            dir.push(dir.front());
        }

        esq.pop();
        dir.pop();
    }

    return 0;
}
