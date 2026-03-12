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
    }

    for (int i = last_idx; i < N; i++) {
        arr[k] = nums[i];
        
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);


}