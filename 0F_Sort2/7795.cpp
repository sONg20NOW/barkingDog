#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;
const int MX = 20001;
int A[MX], B[MX];

bool compare(int a, int b) {
    return a > b;
}

int main() {
    cin >> T;
    while (T--) {
        int res = 0;

        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int j = 0; j < M; j++) {
            cin >> B[j];
        }

        sort(A, A+N, compare);
        sort(B, B+M, compare);

        int ai = 0;
        int bi = 0;
        while (ai < N && bi < M) {
            if (A[ai] > B[bi]) {
                res += (M - bi);
                ai++;
            } else {
                bi++;
            }
        }

        cout << res;
    }
}