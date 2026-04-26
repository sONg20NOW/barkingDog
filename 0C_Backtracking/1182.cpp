#include <bits/stdc++.h>
using namespace std;

int N, S;
int nums[20];
vector<int> arr;
int isused[20];
int num_cnt;

int cnt;

void func(int sum, int st) {
    // cout << "-- S :" << sum << '\n';
    // for (int i : arr) {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    if (sum == S && arr.size() > 0) {
        cnt++;
    }

    for (int i = st; i < N; i++) {
        if (!isused[i]) {
            isused[i] = 1;
            arr.push_back(nums[i]);
            func(sum + nums[i], i + 1);

            isused[i] = 0;
            arr.pop_back();
        }
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + N);

    func(0, 0);

    cout << cnt;
}