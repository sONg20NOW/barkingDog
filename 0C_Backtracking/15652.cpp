#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int st = k == 0 ? 1 : arr[k-1];
    for (int a = st; a <= N; a++) {
        arr[k] = a;
        func(k + 1);
    }
}

int main() {

    cin >> N >> M;

    func(0);
}