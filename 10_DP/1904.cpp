#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 1000001;
int D[MX];
const int MOD = 15746;

int main() {
    cin >> n;
    D[1] = 1;
    D[2] = 2;
    for (int i = 3; i <= n; i++) {
        D[i] = (D[i-1] + D[i-2]) % MOD;
    }

    cout << D[n];
}
