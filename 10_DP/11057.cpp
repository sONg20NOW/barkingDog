#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
const int mod = 10007;
int D[MX][10];

int main() {
    cin >> N;
    for (int i = 0; i < 10; i++) {
        D[1][i] = 1;
    }

    for (int k = 2; k <= N; k++) {
        for (int p = 0; p < 10; p++) {
            for (int j = 0; j <= p; j++) {
                D[k][p] = (D[k][p] + D[k-1][j]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += D[N][i];
    }

    cout << ans;
}