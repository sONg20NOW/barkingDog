#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 501;
int D[MX][MX];
int A[MX][MX];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> A[i][j];
            if (i == n) {
                D[i][j] = A[i][j];
            }
        }
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            D[i][j] = A[i][j] + max(D[i+1][j], D[i+1][j+1]);
        }
    }

    cout << D[1][1];
}