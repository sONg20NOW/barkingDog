#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int arr[10];

void func(int k, int last_idx) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = last_idx; i < N; i++) {
        arr[k] = nums[i];
        func(k + 1, i);
    }
}

int check[10001];

int main() {
    cin >> N >> M;

    int idx = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (!check[tmp]) {
            check[tmp] = 1;
            nums[idx++] = tmp;
        }
    }

    N = idx;
    sort(nums, nums + N);

    func(0, 0);
}