#include <bits/stdc++.h>
using namespace std;

int T;
int N;
const int MX = 41;
int D[MX][2];

int main() {
    cin >> T;
    int mx_n = 1;

    D[0][0] = 1;
    D[1][1] = 1;

    while(T--) {
        cin >> N;
        if (N <= mx_n) {
            cout << D[N][0] << ' ' << D[N][1] << '\n';
            continue;
        }

        for (int k = mx_n + 1; k <= N; k++) {
            D[k][0] = D[k-1][0] + D[k-2][0];
            D[k][1] = D[k-1][1] + D[k-2][1];
        }

        cout << D[N][0] << ' ' << D[N][1] << '\n';

        mx_n = N;
    }
}