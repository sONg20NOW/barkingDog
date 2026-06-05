#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 1001;
int D[MX];

int main() {
    cin >> n;
    D[0] = 1; D[1] = 1;
    for (int i = 2; i <= n; i++) {
        D[i] = (D[i-1] + D[i-2]) % 10007;
    }

    cout << D[n];
}