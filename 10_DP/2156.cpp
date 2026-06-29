#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 10001;
int A[MX];
int D[MX][3];
int ans = -1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    D[1][1] = A[1];
    D[2][1] = A[2];
    D[2][2] = A[1] + A[2];
    ans = D[2][2];

    for (int i = 3; i <= n; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + A[i];
        D[i][2] = A[i] + D[i-1][1];
        ans = max(ans, max(D[i][1], D[i][2]));
    }

    cout << ans;
}