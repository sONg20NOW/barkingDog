#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
int A[MX];
int D[MX];

int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    D[0] = A[0];

    for (int k = 1; k < N; k++) {
        for (int i = 0; i < k; i++) {
            if (A[i] < A[k]) {
                D[k] = max(D[k], D[i] + A[k]);
                ans = max(D[k], ans);
            }
        }
    }

    cout << ans;
}