#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void func(int idx, int max) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = max + 1; i <= N; i++) {
        arr[idx] = i;
        func(idx + 1, arr[idx]);
    }
}

int main() {
    cin >> N >> M;

    func(0, 0);
}