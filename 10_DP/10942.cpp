#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MX = 2001;
int A[MX];
int D[MX][MX];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // 초기값
    for (int i = 1; i <= N; i++) {
        D[i][i] = 1;
        if (A[i-1] == A[i]) D[i-1][i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int gap = 2; i + gap <= N; gap++) {
            int s = i, e = i + gap;
            if (A[s] == A[e] && D[s+1][e-1]) D[s][e] = 1;
        }
    }

    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        
        cout << D[S][E] << '\n';
    }
}