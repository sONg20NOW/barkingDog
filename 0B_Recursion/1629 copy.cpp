#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD(ll A, ll B, ll C) {
    if (B == 1) {
        return A % C;
    }
    ll k = B / 2;
    ll val = MOD(A, k, C);
    val = val * val % C;
    if (B % 2 == 1) {
        return val * A % C;
    } else {
        return val;
    }
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    cout << MOD(A, B, C) << '\n';
}