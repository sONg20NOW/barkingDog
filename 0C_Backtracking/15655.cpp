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

    for (int i = last_idx + 1; i < N; i++) {
        arr[k] = nums[i];
        func(k + 1, i);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    func(0, -1);

}