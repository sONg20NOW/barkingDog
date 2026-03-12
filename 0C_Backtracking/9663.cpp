#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
int isused1[15];
int isused2[30];
int isused3[30];
int arr[15];

void func(int k) {
    if (k == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isused1[i] && !isused2[i + k] && !isused3[k - i + N - 1]) {
            isused1[i] = 1;
            isused2[i + k] = 1;
            isused3[k - i + N - 1] = 1;
            arr[k] = i;
            func(k + 1);
            isused1[i] = 0;
            isused2[i + k] = 0;
            isused3[k - i + N - 1] = 0; 
        }
    }
}

int main() {
    cin >> N;

    func(0);

    cout << cnt << '\n';
}