#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
int A[MX];
int D[MX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    D[0] = 1;
    for (int k = 1; k < N; k++) {
        for (int p = 0; p <= k-1; p++) {
            if (A[p] < A[k])    D[k] = max(D[k], D[p] + 1);
        }
    }

    cout << D[N-1];
}