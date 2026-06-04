#include <bits/stdc++.h>
using namespace std;

int N;
const int MX = (1 << 6) + 1;
int arr[MX];

int makeReverseNum(int n) {
    int res = 0;
    while (n > 0) {
        res *= 10;
        int cur = n % 10;
        res += cur;
        n /= 10;
    }

    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] = makeReverseNum(arr[i]);
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
}