#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 31;
int D[MX];

int main() {
    cin >> N;
    D[0] = 1;
    D[2] = 3;

    if (N % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 2; 2*i <= N; i++) {
        int num = i * 2;
        D[num] += D[num - 2] * 3;
        for (int j = 2; j <= i; j++) {
            D[num] += D[num - 2 * j] * 2;
        }
    }

    cout << D[N];
}