#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> nums;
int arr[10];

void func(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (set<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        arr[k] = *i;
        func(k + 1);
    }
    
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        nums.insert(t);
    }

    func(0);
}