#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int arr[10];
int isused[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            arr[k] = nums[i];
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    func(0);
}