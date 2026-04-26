#include <bits/stdc++.h>
using namespace std;

int N, S;
int nums[20];

int cnt;

void func(int idx, int tot) {
    if (idx == N) {
        if (tot == S)   cnt++;
        return;
    }

    func(idx + 1, tot);
    func(idx + 1, tot + nums[idx]);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    func(0, 0);

    if (S == 0) cnt--;
    cout << cnt;
}