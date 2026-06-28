#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;
int A[MX];
int D[MX];
int N;
int ans;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) {
            D[0] = A[0];
            ans = D[0];
        } else {
            D[i] = max(D[i-1] + A[i], A[i]);
            ans = max(ans, D[i]);
        }
    }
    
    cout << ans;
}