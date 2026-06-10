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
        int min_ans = MX;
        if (i % 3 == 0 && D[i/3] + 1 < min_ans) {
            D[i] = D[i/3] + 1;
            min_ans = D[i];
            pre[i] = i/3;
        } 
        if (i % 2 == 0 && D[i/2] + 1 < min_ans) {
            D[i] = D[i/2] + 1;
            min_ans = D[i];
            pre[i] = i/2;
        } 
        if (D[i-1] + 1 < min_ans) {
            D[i] = D[i-1] + 1;
            min_ans = D[i];
            pre[i] = i-1;
        }
    }

    cout << D[N] << '\n';
    int k = N;
    while (k > 0) {
        cout << k << ' ';
        k = pre[k];
    }
}