#include <bits/stdc++.h>
using namespace std;

int T;
int n;

const int MX = 1000001;
const int mod = 1000000009;
int D[MX];

int main() {
    cin >> T;

    D[1] = 1;
    D[2] = 2;
    D[3] = 4;

    for (int k = 4; k < MX; k++) {
        for (int i = 1; i <= 3; i++) {
            D[k] = (D[k] + D[k-i]) % mod;
        }
    }

    while (T--) {
        cin >> n;

        cout << D[n] << '\n';
    }
}