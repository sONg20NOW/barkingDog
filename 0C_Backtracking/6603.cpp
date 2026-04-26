#include <bits/stdc++.h>
using namespace std;

int nums[13];
int k;
int arr[6];

void func(int n, int last_idx) {
    if (n == 6) {
        for (int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = last_idx + 1; i < k; i++) {
        arr[n] = nums[i];
        func(n + 1, i);
    }
}

int main() {
    while(true) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) {
            cin >> nums[i];
        }

        sort(nums, nums + k);

        func(0, -1);
        cout << '\n';
    }
}