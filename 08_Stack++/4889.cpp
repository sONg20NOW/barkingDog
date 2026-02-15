#include <bits/stdc++.h>
using namespace std;

int main() {

    int prob_num = 1;
    while(true) {
        string s;
        cin >> s;
        if (s.size() > 0 && s[0] == '-') {
            break;
        }

        stack<char> ST;
        int count = 0;
        for (char c : s) {
            if (c == '{') {
                ST.push('{');
            } else if (c == '}') {
                if (ST.empty()) {
                    count++;
                    ST.push('{');
                } else {
                    ST.pop();
                }
            }
        }
        if (!ST.empty()) {
            count += ST.size() / 2;
        }

        cout << prob_num++ << ". " << count << '\n';
    }
}