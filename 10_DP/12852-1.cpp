#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1000001;
int D[MX];
int pre[MX];

int main() {
    cin >> N;
    D[1] = 0;
    pre[1] = 0;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i-1] + 1;
        pre[i] = i-1;
        if (i % 3 == 0 && D[i/3] + 1 < D[i]) {
            D[i] = D[i/3] + 1;
            pre[i] = i/3;
        } 
        if (i % 2 == 0 && D[i/2] + 1 < D[i]) {
            D[i] = D[i/2] + 1;
            pre[i] = i/2;
        } 
    }

    cout << D[N] << '\n';
    int k = N;
    while (k > 0) {
        cout << k << ' ';
        k = pre[k];
    }
}