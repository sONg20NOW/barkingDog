#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 16;
int T[MX];
int P[MX];
int D[MX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i + T[i] >= N)  continue;
        D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);
        ans = max(ans, D[i + T[i]]);
    }

    cout << ans;
}