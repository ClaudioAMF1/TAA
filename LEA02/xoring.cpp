#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string R, S, T;
        cin >> R >> S;

        T = R;

        for (size_t i = 0; i < R.length(); ++i) {
            char r = R[i];
            char s = S[i];

            bool r_maiuscula = (r >= 'A' && r <= 'Z');
            bool r_minuscula = (r >= 'a' && r <= 'z');
            bool s_maiuscula = (s >= 'A' && s <= 'Z');
            bool s_minuscula = (s >= 'a' && s <= 'z');

            if ((r_maiuscula && s_maiuscula) || (r_minuscula && s_minuscula)) {
                if (r_minuscula) {
                    r = r - 32;
                }
            } else {
                if (r_maiuscula) {
                    r = r + 32;
                }
            }

            T[i] = r;
        }

        cout << T << endl;
    }

    return 0;
}
