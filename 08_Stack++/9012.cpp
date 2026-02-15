#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    cin >> N;
    while(N--) {
        string s;
        cin >> s;
        stack<char> ST;
        bool valid = true;
        for (char c : s ) {
            if (c == '(') {
                ST.push('(');
            } else if (ST.empty()) {
                valid = false;
                break;
            } else {
                ST.pop();
            }
        }
        if (!ST.empty())    valid = false;
        cout << (valid ? "YES" : "NO") << '\n';
    }
}