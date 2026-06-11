#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = 1001;
int A[MX];
int D[MX];
int pre[MX];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    D[0] = 1;
    fill(pre, pre + N, -1);

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && (D[j] + 1 > D[i])) {
                pre[i] = j;
                D[i] = D[j] + 1;
            }
        }
    }

    cout << D[N-1] << '\n';
    int idx = N-1;
    stack<int> v;
    while (idx >= 0) {
        v.push(idx);
        idx = pre[idx];
    }

    while (!v.empty()) {
        int top = v.top();  v.pop();
        cout << A[top] << ' ';
    }
}