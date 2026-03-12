#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int isused[10];

// a ~ b까지 cnt 개 수열
void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            arr[k] = i;
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;

    func(0);
}