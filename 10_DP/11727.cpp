#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 1001;
int D[MX];

int main() { 
    cin >> n;
    D[1] = 1;
    D[2] = 3;

    for (int i = 3; i <= n; i++) {
        D[i] = (D[i-1] + D[i-2] * 2) % 10007;
    }

    cout << D[n];
}