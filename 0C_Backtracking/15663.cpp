#include <bits/stdc++.h>
using namespace std;

int N, M;
int nums[10];
int arr[10];

int last_used[10];
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
        // 같은 높이의 이전 트리에서 같은 수를 썼다면 pass
        if (last_used[k] == nums[i] || isused[i])   continue;
        arr[k] = nums[i];
        last_used[k] = nums[i];
        isused[i] = 1;
        func(k + 1);
        isused[i] = 0;
    }
    last_used[k] = 0;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    func(0);
}