#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0;
    int half = (1 << n-1);
    if (r < half) {
        // 1번 사각형
        if (c < half) {
            return func(n-1, r, c);
        } 
        // 2번 사각형
        else {
            return half * half + func(n-1, r, c-half);
        }
    } else {
        // 3번 사각형
        if (c < half) {
            return 2 * half * half + func(n-1, r-half, c);
        } 
        // 4번 사각형
        else {
            return 3 * half * half + func(n-1, r-half, c-half);
        }
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c) << '\n';
}