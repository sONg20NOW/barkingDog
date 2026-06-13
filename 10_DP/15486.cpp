#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1500001;
int T[MX];
int P[MX];
int D[MX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    int ans = 0;
    for (int i = N-1; i >= 0; i--) {
        if (i + T[i] <= N) {
            D[i] = max(D[i + T[i]] + P[i], D[i + 1]);
        } else {
            D[i] = D[i + 1];
        }
        ans = max(ans, D[i]);
    }

    cout << ans;
}