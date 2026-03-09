#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

pair<int,int> func(int k, int m) {
    if (k == 0) return {0, 0};
    int n = 1 << k;
    int half = (n * n) >> 2;
    // cout << "n is " << n << '\n';
    if (m <= half) {
        pair<int,int> t = func(k-1, m);
        return {t.Y, t.X};
    } else if (m <= 2 * half) {
        pair<int,int> t = func(k-1, m - half);
        return {0 + t.X, (n >> 1) + t.Y};
    } else if (m <= 3 * half) {
        pair<int,int> t = func(k-1, m - (2 * half));
        return {(n >> 1) + t.X, (n >> 1) + t.Y};
    } else {
        pair<int,int> t = func(k-1, m - (3 * half));
        return {n - 1 - t.Y, (n >> 1) - 1 - t.X};
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int t_n = n;
    int k = 0;
    while(t_n > 1) {
        t_n = (t_n >> 1);
        k++;
    }

    pair<int,int> result = func(k, m);

    cout << 1 + result.X << ' ' << 1 + result.Y << '\n';
}