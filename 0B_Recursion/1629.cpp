#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD(ll A, ll B, ll C) {
    if (B == 1) {
        return A % C;
    }
    ll k = B / 2;
    ll value = MOD(A, k, C);
    value = value * value % C;

    if (B % 2 == 1) {
        return value * A % C;
    } else {
        return value;
    }
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    cout << MOD(A, B, C) << '\n';
}