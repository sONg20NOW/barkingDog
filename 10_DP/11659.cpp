#include <bits/stdc++.h>
using namespace std;

int N, M;
const int MX = 100001;
int D[MX];
int A[MX];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    D[1] = A[1];
    for (int i = 2; i <= N; i++) {
        D[i] = D[i-1] + A[i];
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        cout << D[b] - D[a-1] << '\n';
    }
}