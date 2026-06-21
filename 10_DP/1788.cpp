#include <bits/stdc++.h>
using namespace std;

const int MX = 1000001;
int D[MX * 2 + 1];
int n;

int* F(int n) {
    return &D[n + MX];
}

int main() {

    cin >> n;
    *F(0) = 0;
    *F(1) = 1;

    if (n < 0) {
        cout << -1 << '\n';
        for (int i = -1; i >= n; i--) {
            *F(i) = *F(i+2) - *F(i+1);
        }
        cout << abs(*F(n)) << '\n';
    } else if (n == 0) {
        cout << 0 << '\n';
        cout << *F(0) << '\n';
    } else {
        cout << 1 << '\n';
        for (int i = 2; i <= n; i++) {
            *F(i) = *F(i-1) + *F(i-2);
        }
        cout << *F(n) << '\n';
    }
}