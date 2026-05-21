#include <bits/stdc++.h>
using namespace std;

const int MX = 1001;
string s;
string subs[MX];

int main() {
    cin >> s;

    int N = s.length();

    for (int i = 0; i < N; i++) {
        subs[i] = s.substr(i, N);
    }

    sort(subs, subs+N);

    for (int i = 0; i < N; i++) {
        cout << subs[i] << '\n';
    }
}