#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 101;
const int mod =1000000000;
int D[MX][10];

int main() {
    cin >> N;
    for (int i = 1; i < 10; i++) {
        D[1][i] = 1;
    }

    for (int k = 2; k <= N; k++) {
        for (int i = 0; i < 10; i++) {
            D[k][i] = (i-1 >= 0 ? D[k-1][i-1] : 0) + (i+1 <= 9 ? D[k-1][i+1] : 0);
            D[k][i] %= mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += D[N][i];
    }

    cout << ans << '\n';
}