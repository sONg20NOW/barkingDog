#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
int C[MX];
int D[MX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }

    D[0] = 0;
    D[1] = C[1];
    for (int i = 2; i <= N; i++) {
        int ans = D[i-1];
        for (int j = 1; j <= i; j++) {
            ans = max(ans, D[i-j] + C[j]);
        }
        D[i] = ans;
    }

    cout << D[N];
}